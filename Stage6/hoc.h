typedef struct symbol 
{
	char *name; //name of symbol
	short type; //VAR, BUILT IN,CNST and UNDEF (seen but not defined yet)
	union
	{
		double val; //if its a variable
		double (*ptr)(); //if its a builtin, u.ptr is a pointer to a function that returns double
		int (*defn)(); //function or procedure
		char *str; //string 
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
#define contcode (Inst)8
#define breakcode (Inst)4

extern Inst *prog, *progp, *code(Inst f), *progbase;
extern int eval(), add(), sub(), mul(), div_(), negate(), power(), mod(), sys(), prevset(), define(symbol* sp), call();
extern int assign(), bltin(), varpush(), constpush(), print(), funcret(), procret(), ret(), arg(), argassign();
extern int varread();
extern int prexpr(), prstr();
extern int gt(), ge(), lt(), le(), eq(), ne(), and_(), or_(), not_(), inc(), dec();
extern int ifcode(), whilecode(), forcode();
