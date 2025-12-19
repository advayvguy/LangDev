%{
#include <stdio.h>
#include <ctype.h>
int yylex(void);
void yyerror(const char *s);
int lineno = 1;
char *progname;
%}

%{
#define YYSTYPE double
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%token UNARYMINUS
%%
list:
    	| list '\n'
    	| list expr '\n' {printf("\t%.8g\n",$2); }
	;

expr:	  NUMBER {$$ = $1; }
		| '-' expr %prec UNARYMINUS {$$ = -$2; }
		| expr '+' expr {$$ = $1 + $3; }
		| expr '%' expr {$$ = (int)$1 % (int)$3; }
		| expr '-' expr {$$ = $1 - $3; }
		| expr '*' expr {$$ = $1 * $3; }
		| expr '/' expr {$$ = $1 / $3; }
		| '(' expr ')' {$$ = $2; }
%%

/* end of grammar */

int main(int argc, char **argv)
{
	progname = argv[0];
	yyparse();
}

/* yyparse repeatead called yylex until EOF is encountered*/

int yylex()
{
	int c;
	while ((c = getchar()) == ' ' || c == '\t');
	if (c == EOF) return 0;
	if (c == '.' || isdigit(c))
	{
		ungetc(c, stdin);
		scanf("%lf",&yylval);
		return NUMBER; //we return NUMBER if we enounter a float type
	}
	if (c == '\n') lineno++;
	return c; 
}

/* yyval is a variable created by yyparse, yylex sends the token to yyparse through yyval */
/* %token NUMBER is converted to #define constant by yacc (doesnt coincide with the ascii values)*/

/* if there is a syntax error yyparse calls yyeror */

void yyerror(const char *s)
{
	fprintf(stderr, "%s: %s in line %d\n",progname, s, lineno);
} 
