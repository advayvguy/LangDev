%{

//all standard libraries are included here
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include "hoc.h" // for lookup and install

extern double Pow(double a, double b); //belongs to math.c, Pow is invoked when '^' is encountered
extern void init(); //belongs to init.c, this initilaizes the constants and the builtins

int yylex(void); //for lexing, sending values through yylval and returning its token type
double _ = 0; //remembers its previous value
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
	double val; //double type
	symbol *sym; //symbol table pointer type
}

%token <val> NUMBER
%token <sym> VAR BLTIN UNDEF CNST BLTIN2 BLTIN0 SYS//var- a variable that exists in the lookup table
														 //builtin- builtin functions
														 //undef- freshly declared vars, once they are defined, they convert to var
%type  <val> asgn expr       // $$ is of val type
%right '='
%left '+' '-'
%left '*' '/' '%'
%left  UNARYMINUS
%right '^' //2 ^ 2 ^ 3 is 2^8 not 4^3 therefore its is right associtative

%%
list:	
			|list SYS '\n'		 							{system($2->name); } //$2 is the string here that we are going to execute
    	|list '\n'
			|list asgn '\n'									
			|list error '\n' 								{yyerrok; } //a flag to reassure that the error has been taken care of
			|list expr '\n' 								{ printf("\t%0.6lf\n",$2); _ = $2; }
			|list ';'
			|list asgn ';'
			|list error ';'									{yyerrok; }
			|list expr ';'									{_ = $2; }

asgn:	 VAR '=' expr 									{$$ = $1->u.val = $3; $1->type = VAR; }
			|CNST '=' expr									{execerror("constant cant be changed",$1->name); }

expr: 	 NUMBER
    		|VAR													{if($1->type == UNDEF) execerror("undefined variable",$1->name); $$ = $1->u.val; } 
				|CNST													{$$ = $1->u.val; }
				|asgn
				|BLTIN '(' expr ')' 					{$$ = (*($1->u.ptr))($3); }
				|BLTIN2 '(' expr ',' expr ')'	{$$ = (*($1->u.ptr))($3,$5); }
				|BLTIN0 '(' ')'								{$$ = (*($1->u.ptr))(); }
				|expr '+' expr 	    					{$$ = $1 + $3; }
				|expr '-' expr  	    				{$$ = $1 - $3; }
				|expr '*' expr	      				{$$ = $1 * $3; }
				|expr '/' expr								{if($3 == 0) execerror("cant divide by zero",""); $$ = $1 / $3; }
				|expr '%' expr								{if($3 == 0) execerror("cant divide by zero",""); $$ = (int)$1 % (int)$3; }
				|expr '^' expr     						{$$ = Pow($1,$3); }
				|'(' expr ')'    							{$$ = $2; }
				| '-' expr  %prec UNARYMINUS	{$$ = -$2; }
%%

int yylex(void)
{
	int c; 
	while ((c = getchar()) == ' ' || c == '\t') ; //get rid of blanks
	if (isdigit(c) || c == '.') 
	{
		ungetc(c,stdin);
		scanf("%lf",&yylval.val);
		return NUMBER;
	} //just return the plain old number when you see one

	else if (isalpha(c))
	{
		symbol *s;
		char sbuf[100]; 
		char *p = sbuf;
		do
		{
			*p++ = c;
		} while ((c = getchar()) != EOF && isalnum(c));
		ungetc(c, stdin);
		*p = '\0';
		if ((s = lookup(sbuf)) == 0) s =  install(sbuf, UNDEF, 0.0); //if sbuf is not present in the table, then we add it and set it to undef
		yylval.sym = s; 
		return s->type == UNDEF ? VAR : s->type; //if the type is undef, return VAR else return s->type (builtin or var)
	}
	else if (c == '_')
	{
		yylval.val = _;
		return NUMBER;
	}
	else if (c == '!')
	{
		char sbuf[100];
		int i = 0,c;
		while ((c = getchar()) != '\n')
		{
			sbuf[i++] = c;
		}
		sbuf[i] = '\0';
		ungetc(c,stdin);
		symbol *s = install(sbuf, SYS, 0.0);
		yylval.sym = s;
		return SYS;
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
	yyparse();
}
