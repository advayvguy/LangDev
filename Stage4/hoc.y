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
extern Inst *code(Inst p);
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

%token <sym> NUMBER VAR BLTIN UNDEF CNST BLTIN2 BLTIN0 SYS//var- a variable that exists in the lookup table
														 //builtin- builtin functions
														 //undef- freshly declared vars, once they are defined, they convert to var
%right '='
%left '+' '-'
%left '*' '/' '%'
%left  UNARYMINUS
%right '^' //2 ^ 2 ^ 3 is 2^8 not 4^3 therefore its is right associtative

%%
list:	
    	|list '\n'									
			|list asgn '\n'									{code3(prevset, (Inst)pop, STOP); return 1; }
			|list error '\n' 								{yyerrok; } //a flag to reassure that the error has been taken care of
			|list expr '\n' 								{code3(prevset, print, STOP); return 1; }
			|list ';'
			|list asgn ';'
			|list error ';'									{yyerrok; }
			|list expr ';'									{code(prevset);}
			|list SYS '\n'          	 			{code3(varpush, (Inst)$2 ,sys); } //$2 is the string here that we are going to execute

asgn:	 VAR '=' expr 									{ code3(varpush, (Inst)$1, assign); }
			|CNST '=' expr									{execerror("constant cant be changed",$1->name); }

expr: 	 NUMBER												{code2(constpush, (Inst)$1); }
    		|VAR													{if($1->type == UNDEF) execerror("undefined variable",$1->name); code3(varpush, (Inst)$1, eval); } 
				|CNST													{code2(constpush, (Inst)$1); }
				|asgn
				|BLTIN '(' expr ')' 					{code2(bltin, (Inst)$1); }
				|BLTIN2 '(' expr ',' expr ')'	{code2(bltin, (Inst)$1); }
				|BLTIN0 '(' ')'								{code2(bltin, (Inst)$1); }
				|expr '+' expr 	    					{code(add); }
				|expr '-' expr  	    				{code(sub); }
				|expr '*' expr	      				{code(mul); }
				|expr '/' expr								{code(div_); }
				|expr '%' expr								{code(mod); }
				|expr '^' expr     						{code(power); }
				|'(' expr ')'    						
				| '-' expr  %prec UNARYMINUS	{code(negate); }
%%

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
	if (c == '\n') lineno++;
	return c;
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
