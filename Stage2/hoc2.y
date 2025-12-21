%{

/*standard stuff so far until now*/

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

int yylex(void);
double mem[26];
int lineno = 1;
char *progname;
jmp_buf begin;
void fpecatch();
void execerror(char *s,char *t);
void warning(char *s, char *t);
void yyerror(char *s);
double _ = 0;

%}

%union { double val; int index; } //the stack elements hold either a double or an int
%token <val> NUMBER //token- NUMBER is of the type <val> or double
%token <index> VAR //token- VAR is of the type <index> or int
%type <val> expr // expr belongs to <var> in the union which is a float type
%right '='
%left '+' '-'
%left '*' '/' '%'
%left UNARYMINUS

%%
list:	
    	|list '\n'
    	|list expr '\n' { _  = $2; printf("\t%0.8g\n",$2); }
	|list error '\n' {yyerrok; } //yyerrok-> sets back to a sensible previous state in case an error is handled
	|list ';'
	|list expr ';' {_ = $2; }
	|list error ';'

expr:
    	 NUMBER
	|VAR {$$= mem[$1]; }
	|VAR '=' expr {$$ = mem[$1] = $3; }
	|expr '+' expr {$$ = $1 + $3; }
	|expr '-' expr {$$ = $1 - $3; }
	|expr '*' expr {$$ = $1 * $3; }
	|expr '/' expr {if ($3 == 0) execerror("divison by zero", ""); $$ = $1/$3; }
	|expr '%' expr {if ($3 == 0) execerror("division by zero",""); $$ = (int)$1 % (int)$3; }
	|'(' expr ')' {$$ = $2; }
	| '-' expr %prec UNARYMINUS {$$ = -$2; }
%%

/* end of grammar */

int main(int argc, char **argv)
{
	progname = argv[0];
	setjmp(begin);
	signal(SIGFPE, fpecatch);
	yyparse();
}

void warning(char *s,char *t)
{
	fprintf(stderr,"line %d -> %s: %s\n",lineno,t,s);
}

void execerror(char *s, char *t)
{
	warning(s,t);
	longjmp(begin, 0);
}

void yyerror(char *s)
{
	warning(s, "");
}

void fpecatch()
{
	execerror("floating point error",NULL);
}

int yylex()
{
	int c;
	while((c = getchar()) == ' ' || c == '\t');
	if (c == EOF) return 0;
	if (c == '.' || isdigit(c))
	{
		ungetc(c, stdin);
		scanf("%lf",&yylval.val);
		return NUMBER; 
	}
	if (c == '_')
	{
		yylval.val = _;
		return NUMBER;
	}	
	if (islower(c))
	{
		yylval.index = c - 'a';
		return VAR;
	}
	if (c == '\n') lineno++;
	return c;
}

















