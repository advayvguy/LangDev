typedef struct symbol 
{
	char *name; //name of symbol
	short type; //VAR, BUILT IN,CNST and UNDEF (seen but not defined yet)
	union
	{
		double val; //if its a variable
		double (*ptr)(); //if its a builtin, u.ptr is a pointer to a function that returns double
	} u;
	struct symbol *next; //a linked list (for the symbol table)
} symbol;

symbol *install(char *s, int t, double d), *lookup(char *s); //we are making two functions here
			      //install- returns the pointer to the node symbol
			      //lookup- returns the pointer to the node with the matching name

typedef union Datum
{
	double val;
	symbol *sym;
} Datum; //interpreter stack type

extern Datum pop();

typedef int (*Inst)();
#define STOP (Inst)0 //STOP- value- NULL; type- pointer to a function that returns int

extern Inst *prog, *progp, *code(Inst f);
extern int eval(), add(), sub(), mul(), div_(), negate(), power(), mod(), sys(), prevset();
extern int assign(), bltin(), varpush(), constpush(), print();
extern int prexpr();
extern int gt(), ge(), lt(), le(), eq(), ne(), and_(), or_(), not_();
extern int ifcode(), whilecode();


