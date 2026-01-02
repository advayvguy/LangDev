%{

//all standard libraries are included here
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include "hoc.h" // for lookup and install

#define code2(c1,c2) code(c1) ; code(c2)
#define code3(c1,c2,c3) code(c1) ; code(c2) ; code(c3)

extern double Pow(double a, double b); //belongs to math.c, Pow is invoked when '^' is encountered
extern void init(); //belongs to init.c, this initilaizes the constants and the builtins
extern int initcode();
extern int execute(Inst *p);

int yylex(void); //for lexing, sending values through yylval and returning its token type
int lineno = 1; 
char *progname;

jmp_buf begin; //we define a jum_buf struct- begin which would hold the timestamps and the necesary details with we setjmp

//some error catching functions
void fpecatch(); //for floating point errors
void execerror(const char *s, const char *t); //resets the state and gives warning the parameters
void warning (const char *s, const char *t); //prints on stderr
void yyerror(char *s); //called upon by yylex for misc errors

%}

%union
{
	Inst *inst; //machine instruction
	symbol *sym; //symbol table pointer type
}

%token <sym> NUMBER VAR BLTIN UNDEF CNST BLTIN2 BLTIN0 SYS WHILE IF ELSE PRINT BREAK CONTINUE FOR
%type  <inst> stmt asgn expr stmtlist cond while if end newl break continue for fexpr
%right '='
%left OR
%left AND
%left GT GE LT LE EQ NE INC DEC
%left '+' '-'
%left '*' '/' '%'
%left  UNARYMINUS NOT
%right '^' //2 ^ 2 ^ 3 is 2^8 not 4^3 therefore its is right associtative

%%
list:	
    	|list '\n'								
			|list asgn '\n'									{code3(prevset, (Inst)pop, STOP); return 1; }
			|list error '\n' 								{yyerrok; } //a flag to reassure that the error has been taken care of
			|list expr '\n' 								{code3(prevset, print, STOP); return 1; }
			|list stmt '\n'									{code(STOP); return 1; }
			|list ';'
			|list asgn ';'
			|list error ';'									{yyerrok; }
			|list expr ';'									{code(prevset);}
			|list stmt ';'									{code(STOP); return 1; }
			|list SYS '\n'          	 			{code3(varpush, (Inst)$2 ,sys); } //$2 is the string here that we are going to execute

asgn:	 VAR '=' expr 									{$$ = $3; code3(varpush, (Inst)$1, assign); }
			|CNST '=' expr									{execerror("constant cant be changed",$1->name); }

stmt: 	expr 																		{code((Inst)pop); }
				|break
				|continue
				|PRINT expr 															{code(prexpr); $$ = $2; }
				|for '(' fexpr ';' fexpr ';' fexpr ')' newl stmt end 	{	($1)[1] = (Inst)$3; 
																															($1)[2] = (Inst)$5;
																															($1)[3] = (Inst)$7; 
																															($1)[4] = (Inst)$10;
																															($1)[5] = (Inst)$11; }

				|while cond newl stmt end 											{($1)[1] = (Inst)$4; ($1)[2] = (Inst)$5; }
				|if cond newl stmt end													{($1)[1] = (Inst)$4; ($1)[3] = (Inst)$5; }
				|if cond newl stmt end ELSE newl stmt end 			{($1)[1] = (Inst)$4; ($1)[2] = (Inst)$8; ($1)[3] = (Inst)$9; }
				|'{' stmtlist '}'																{$$ = $2; }


cond:		'(' expr ')' 									{code(STOP); $$ = $2; }

while:	WHILE													{$$ = code3(whilecode, STOP, STOP); }


for: 		FOR 													{$$ = code3(forcode, STOP, STOP); code3(STOP,STOP,STOP);}

if:			IF 														{$$ = code(ifcode); code3(STOP,STOP,STOP); }

end:																	{code(STOP); $$ = progp; }

stmtlist:															{$$ = progp; }
				|stmtlist newl
				|stmtlist stmt newl

fexpr:	expr 												{code(STOP); $$ = $1; }

expr: 	 NUMBER												{$$ = code2(constpush, (Inst)$1); }
    		|VAR													{$$ = code3(varpush, (Inst)$1, eval); } 
				|VAR INC											{$$ = code3(varpush, (Inst)$1, inc); }
				|VAR DEC											{$$ = code3(varpush, (Inst)$1, dec); }
				|CNST													{$$ = code2(constpush, (Inst)$1); }
				|asgn                         
				|BLTIN '(' expr ')' 					{$$ = $3; code2(bltin, (Inst)$1); }
				|BLTIN2 '(' expr ',' expr ')'	{$$ = $5; code2(bltin, (Inst)$1); }
				|BLTIN0 '(' ')'								{code2(bltin, (Inst)$1); }
				|expr '+' expr 	    					{code(add); }
				|expr '-' expr  	    				{code(sub); }
				|expr '*' expr	      				{code(mul); }
				|expr '/' expr								{code(div_); }
				|expr '%' expr								{code(mod); }
				|expr '^' expr     						{code(power); }
				|'(' expr ')'    							{$$ = $2; }	
				| '-' expr  %prec UNARYMINUS	{$$ = $2; code(negate); }
				|expr GT expr 								{code(gt); }
				|expr GE expr									{code(ge); }
				|expr LT expr									{code(lt); }
				|expr LE expr									{code(le); }
				|expr EQ expr									{code(eq); }
				|expr NE expr 								{code(ne); }
				|expr AND expr								{code(and_); }
				|expr OR expr 								{code(or_); }
				|NOT expr 										{$$ = $2; code(not_); }

break:	BREAK													{$$ = code(breakcode); }

continue: CONTINUE										{$$ = code(contcode); }

newl: 
			 |'\n'
			 |newl '\n'
%%

int follow(int expect, int ifyes, int ifno)
{
	int c = getchar();
	if (c == expect) return ifyes;
	ungetc(c,stdin);
	return ifno;
}

int yylex(void)
{
	int c; 
	while ((c = getchar()) == ' ' || c == '\t') ; //get rid of blanks
	if (isdigit(c) || c == '.') 
	{
		double d;
		ungetc(c,stdin);
		scanf("%lf",&d);
		yylval.sym = install("", NUMBER, d); //we are adding the number to the symbol table, we dont assign a name to it.
		return NUMBER;
	} 
	else if (isalpha(c))
	{
		symbol *s;
		char sbuf[100]; 
		char *p = sbuf;
		do
		{
			*p++ = c;
		} while ((c = getchar()) != EOF && isalnum(c));
		if (strcmp("sys",sbuf) == 0)
		{
			if (c == '-')
			{
				char buf[100];
				int i = 0,c;
				while((c = getchar()) != '\n')
				{
					buf[i++] = c;
				}
				buf[i] = '\0';
				ungetc(c,stdin);
				symbol *s = install(buf, SYS, 0.0);
				yylval.sym = s;
				return SYS;
			}
			else execerror("sys is a builtin command","");
		}
		ungetc(c, stdin);
		*p = '\0';
		if ((s = lookup(sbuf)) == 0) s =  install(sbuf, UNDEF, 0.0); //if sbuf is not present in the table, then we add it and set it to undef
		yylval.sym = s; 
		return s->type == UNDEF ? VAR : s->type; //if the type is undef, return VAR else return s->type (builtin or var)
	}
	else if (c == '_')
	{
		yylval.sym = lookup("_");
		return VAR;
	}
	if (c == '/')
	{
		int checkcom = follow('/', 1, 0);
		if (checkcom)
		{
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
	switch(c)
	{
	case '>': return follow('=',GE,GT);
	case '<': return follow('=',LE,LT);
	case '=': return follow('=',EQ,'=');
	case '!': return follow('=',NE,NOT);
	case '|': return follow('|',OR,'|');
	case '&': return follow('&',AND,'&');
	case '+': return follow ('+',INC,'+'); 
	case '-':  return follow ('+',DEC,'+'); 
	case '\n': lineno++; return '\n';
	default: return c;
	}
} 

void fpecatch()
{
	execerror("floating point error","");
}

void yyerror(char *s)
{
	execerror(s, "");
}

void warning(const char *s, const char *t)
{
	fprintf(stderr,"\033[0;31m line no:- %d|%s %s \033[0m\n",lineno, (strcmp(t,"") == 0) ? "":t, s);
}

void execerror(const char *s, const char *t)
{
	warning (s,t);
	longjmp(begin, 0);	
}

int main(int argc, char **argv)
{
		
	progname = argv[0];	
	init();
	setjmp(begin);
	signal(SIGFPE, fpecatch);
	for (initcode(); yyparse(); initcode()) execute(prog); //yyparse() will return 0 at the end of file
	return 0;
}
