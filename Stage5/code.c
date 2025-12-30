//contains routines that execute  machine instructions and manipulate the stack

#include "hoc.h"
#include "hoc.tab.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern void execerror(const char *s, const char *t);
extern Datum dispatch (Datum p1, Datum p2, symbol *s);
extern void echeck(double val);


static Datum *stack;
Inst *prog;

void makebufs()
{
	
	prog = (Inst *)malloc(sizeof(Inst)*2000); //array containing a set of programs
	stack = (Datum *)malloc(sizeof(Datum)*1000); //stack on which th operations are being performed
}

static Datum *stackp; //returns the pointer to the next free spot on the stack
static int sizes = 1000;

#define NPROG 2000

Inst *pc; //program counter, after all the programs are loaded in the prog array and its time to execute
Inst *progp; //keeps track of the instructions in the prog (while the instructions are being read)
static int sizep = 2000;

void initcode()
{
	stackp = stack;
	progp = prog;
}

//main calls to manipulate the stack

void push(Datum d) //pushes d into the stack
{
	if (stackp >= &stack[sizes])
	{
		sizes += 1000;
		void *check = realloc(stack, sizeof(Datum)*sizes);
		if (check == NULL) execerror("no space available in stack","");
		else stack = (Datum *)check;
	}
	*(stackp++) = d;
}

Datum pop() //pops the top element from the stack
{
	if (stackp <= stack) execerror("nothing left to pop","");
	return *(--stackp);
}

//prog-> array of pointers to a functionr returning int

Inst *code(Inst f) //code returns a pointer to Inst, Inst-> pointer to a function returning int
{
	Inst *oprogp = progp;
	if (progp >= &prog[sizep])
	{
		sizep += 2000;
		void *check = realloc(prog, sizeof(Inst)*sizep);
		if (check == NULL) execerror("no space available for storing programs","");
		else prog = (Inst *)check;
	}
	*(progp++) = f;
	return oprogp; //where the current program is stored, not the pointer to the next free space
}

int execute(Inst *p) //p has the address of the cell with the instruction
{
	for (pc = p; *pc != STOP; ) (*(*pc++))(); //*p -> decays to pointer to a function, and (*pointer to a function)() decays to the function itsel
	return 2;																				 //we keep incrementing the program counterf
}

int constpush()
{
	Datum d;
	d.val = ((symbol *)*pc++)->u.val;
	push(d);
	return 2;
}

int varpush()
{
	Datum d;
	d.sym = (symbol *)(*pc++);
	if (*pc != assign && d.sym->type == UNDEF) execerror("is not defined",d.sym->name);
	push(d);
	return 2;
}

int add()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val += d2.val;
	push(d1);
	return 2;
}

int sub()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val -= d2.val;
	push(d1);
	return 1;
}

int mul()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val *= d2.val;
	push(d1);
	return 2;
}

int div_()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	if (d2.val == 0) execerror("cant divide by 0","");
	d1.val /= d2.val;
	push(d1);
	return 2;
}

int mod()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	if (d2.val == 0) execerror("cant divide by 0","");
	int mod_val = (int)(d1.val) % (int)(d2.val);
	d1.val = (float)mod_val;
	push(d1);
	return 2;
}

int power()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val = pow(d1.val, d2.val);
	push(d1);
	return 2;
}

int negate()
{
	Datum d1 = pop();
	d1.val = -d1.val;
	push(d1);
	return 2;
}

int sys()
{
	Datum d1 = pop();
	system(d1.sym->name);
	return 2;
}

int eval()
{
	Datum d;
	d = pop();
	if (d.sym->type == UNDEF) execerror("undefined variable",d.sym->name);
	d.val = d.sym->u.val;
	push(d);
	return 2;
}

int assign() //assign top value to the next value
{
	Datum d1, d2; 
	d1 = pop();
	d2 = pop();
	if (d1.sym->type != VAR && d1.sym->type != UNDEF) execerror("assignment to a non variable",d1.sym->name);
	d1.sym->u.val = d2.val;
	d1.sym->type = VAR;
	push (d2);
	return 2;
}

int print()
{
	Datum d;
	d = pop();
	printf("\t%0.6lf\n",d.val);
	return 2;
}

int bltin()
{
	symbol *s = (symbol *)*pc++;
	int type = s->type;
	Datum p1, p2;
	if (type == BLTIN) p1 = pop();
	else if (type == BLTIN2) {p2 = pop(); p1 = pop();}
	push (dispatch(p1, p2, s));
	return 2;
}

int prevset()
{
	symbol *s = lookup("_");
	Datum d1 = pop();
	s->u.val = d1.val;
	push(d1);
	return 2;
}

int whilecode()
{
	Datum d;
	Inst *savepc = pc; 
	execute(savepc+2);
	d = pop(); //we evaluate the condtion here;
	while (d.val)
	{
		execute(*((Inst **)(savepc))); // run the body
		execute(savepc+2); //we check for the condtion again here
		d = pop();
	}
	pc = *((Inst **)(savepc+1));//next statement
	return 2;
}

int ifcode()
{
	Datum d;
	Inst *savepc = pc;

	execute(savepc+3);
	d = pop();
	if (d.val) execute(*((Inst **)(savepc)));
	else if (*((Inst **)(savepc+1))) execute(*((Inst **)(savepc+1)));
	pc = *((Inst **)(savepc+2));
	return 2;
}

int prexpr()
{
	Datum d = pop();
	printf("\t%.6lf\n", d.val);
	return 2;
}

//now for the trivial operators

int ge()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val >= d2.val);
	push(d1);
	return 2;
}

int gt()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val > d2.val);
	push(d1);
	return 2;
}

int le()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val <= d2.val);
	push(d1);
	return 2;
}

int lt()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val < d2.val);
	push(d1);
	return 2;
}

int eq()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val == d2.val);
	push(d1);
	return 2;
}

int ne()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val != d2.val);
	push(d1);
	return 2;
}

int and_()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val && d2.val);
	push(d1);
	return 2;
}

int or_()
{
	Datum d2 = pop();
	Datum d1 = pop();
	d1.val = (double)(d1.val || d2.val);
	push(d1);
	return 2;
}

int not_()
{
	Datum d = pop();
	d.val = !(d.val);
	push(d);
	return 2;
}
