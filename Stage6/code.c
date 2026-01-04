//contains routines that execute  machine instructions and manipulate the stack

#include "hoc.h"
#include "hoc.tab.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define B 4
#define C 8

extern void execerror(const char *s, const char *t);
extern Datum dispatch (Datum p1, Datum p2, symbol *s);
extern void echeck(double val);


static Datum *stack;
Inst *prog;

static Datum *stackp; //returns the pointer to the next free spot on the stack
static int sizes = 1000;

#define NPROG 2000

Inst *pc; //program counter, after all the programs are loaded in the prog array and its time to execute
Inst *progp; //keeps track of the instructions in the prog (while the instructions are being read)
static int sizep = 2000;
Inst *progbase; //start of current subprogram
int returning = 0; //1 if return statement is seen

typedef struct Frame 
{
	symbol *sp;  //keeps in track of all the symbol table entries in a function
	Inst *retpc; //where to return the program after the return statement is seen
	Datum *argn; //nth argument on the stack
	int nargs; //number of arguments
} Frame;

Frame *frame; //recursive/fucntion calls within functions 
Frame *fp;
static int nframe = 100;

void makebufs()
{
	
	prog = (Inst *)malloc(sizeof(Inst)*2000); //array containing a set of programs
	stack = (Datum *)malloc(sizeof(Datum)*1000); //stack on which th operations are being performed
	frame = (Frame *)malloc(sizeof(Frame)*100); //create the frame stacki
	progbase = prog;
}

void initcode()
{
	progp = progbase; //probably to keep building on the stack after the function is defined, instead of flushing it out
	stackp = stack;
	fp = frame; //every function keeps one frame to store relevent information
	returning = 0;
}

int define(symbol *sp) //right now the function name is stored as a var type
{
	sp->u.defn = (Inst)progbase; //the beginning of the program 
	progbase = progp; 					 //progp right now is at the end of the program, therefore we set progbase to progp so that the function is
	return 2;										//remembered
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
	for (pc = p; *pc != STOP && !returning; ) 
	{
			if (*pc == breakcode) return B;
			else if (*pc == contcode)  return C;
			int check = (*(*pc++))();
			if (check == B) return B;
			else if (check == C) return C;
	}
	return 2;
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
	while (1)
	{
		
		execute(savepc+2);
		d = pop(); //we evaluate the condtion here;
		if (d.val == 0) break;

		int check = execute(*((Inst **)(savepc))); // run the body
		if (check == B) break;
		else if (check == C) continue;
	}
	if (!returning ) pc = *((Inst **)(savepc+1));//next statement
	return 2;
}

int forcode()
{
	Inst *savepc = pc;
	execute(*((Inst **)(savepc)));
	Datum d;
	while (1)
	{
		execute(*((Inst **)(savepc+1)));
		d = pop(); //we evaluate the condtion here;
		if (d.val == 0) break;

		int check = execute(*((Inst **)(savepc+3))); // run the body
		if (check == B) break;
		execute(*((Inst **)(savepc+2)));
		if (check == C) continue;
	}
	if ( !returning  ) pc = *((Inst **)(savepc+4));//next statement
	return 2;
}

int ifcode()
{
	Datum d;
	Inst *savepc = pc;

	execute(savepc+3);
	d = pop();
	if (d.val) 
	{
		int check = execute(*((Inst **)(savepc))); 
		if (check == B) return B;
		else if (check == C) return C;
	}
	else if (*((Inst **)(savepc+1))) 
	{
		int check = execute(*((Inst **)(savepc+1)));
		if (check == B) return B;
		else if (check == C) return C;
	}
	if( !returning ) pc = *((Inst **)(savepc+2));
	return 2;
}

int isinteger(double x) 
{
    if (!isfinite(x)) return 0;
    return fabs(x - nearbyint(x)) <= DBL_EPSILON * fabs(x);
}

int prexpr()
{
	Datum d = pop();
	if (isinteger(d.val)) printf("%d",(int)d.val);
	else printf("%.6lf", d.val);
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

int inc()
{
	Datum d; 
	d = pop();
	if (d.sym->type != VAR) execerror("variable is undefined",d.sym->name);
	d.sym->u.val = d.sym->u.val + 1;
	push (d);
	return 2;
}

int dec()
{
	Datum d; 
	d = pop();
	if (d.sym->type != VAR) execerror("variable is undefined",d.sym->name);
	d.sym->u.val = d.sym->u.val - 1;
	push (d);
	return 2;
}


//how the program memory looks like-
//   |  CALL  |  ->  |  (Inst)FUNCTION  /  ->  /  (Inst)ARGLIST  / 
//   										^^^^^^^^^^^^^^
//   													PC

int call()
{
	symbol *s = (symbol *)pc[0];

	if (fp++ >= &frame[nframe - 1])
	{
		nframe += 100;
		Frame *check = (Frame *)realloc(frame, sizeof(Frame)*nframe);
		if (check == NULL) execerror(s->name, "call nested too deeply");
		else frame = check;
	}
	fp->sp = s;
	fp->nargs = (int)pc[1];
	fp ->retpc = pc + 2;
	fp->argn = stackp - 1; //last argument
	execute(s->u.defn);   //s->u.defn = the first instruction 
	returning = 0;
	return 2;
}

int funcret()
{
	Datum d;
	if (fp->sp->type == PROCEDURE) execerror(fp->sp->name,"(void) returns value");
	d = pop();
	ret();
	push(d);
	return 2;
}

int procret()
{
	if(fp->sp->type == FUNCTION) execerror(fp->sp->name,"(func) returns no value");
	ret();
	return 2;
}

int ret()
{
	int i;
	for(i = 0; i < fp->nargs; i++)
	{
		pop();
	}
	pc = (Inst *)fp->retpc;
	--fp;
	returning = 1;
	return 2;
}

/*							| 10 | 20 | 30 
														^^					
														fp->argn
								
								$2 -> nargs = 2;
								argn[2-3].val = 20;
								therore 
								getarg = | 20 |
*/

double *getarg()
{
	int nargs = (int)*pc++;
	if (nargs > fp->nargs) execerror(fp->sp->name, "not enough arguments");
	return &fp->argn[nargs - fp->nargs].val; 
}


//how the program memory looks like
//																/  ARG  / -> /  Inst_2 (for example)  / -> /  next bytecode  /
//																							^^^^^^^^^^^^^^^^^^^^^^^^
//																												PC
																											
int arg() //pushes the argument into the stack
{
	Datum d;
	d.val = *getarg();
	push(d);
	return 2;
}

/*
 																/ 	ARGASSIGN 	/ -> /  INST_2  / -> /  next bytecode  /
																											^^^^^^^^^
																													PC

*/

int argassign()
{
	Datum d;
	d = pop(); //we get the value evaluated from the expr here
	push(d);
	*getarg() = d.val; //-> we change the value of $2 to d
	return 2;
}

int prstr()
{
	printf("%s",(char *)*pc++);
	return 2;
}

/*
 										input- read(x)
										read -> BLTIN for varread
										tokens -
										BLTIN -> expr
										how its added to the program memory- 
										/  varread  / -> /  (Inst)expr  / -> /  next bytecode  /
																				^^^^^^^^^^
																						PC
*/
int varread()
{
    Datum d;
    double cval;
    if (fscanf(stdin, "%lf", &cval) != 1) {
        getc(stdin); 
        execerror("non number to read into", "");
    } else {
			d.val = cval;
			push(d);
    }
    return 2;
}

int arrinit()
{
	symbol *sp = (symbol *)*pc++;
	Datum d = pop();
	if (!isinteger(d.val)) execerror("non integral index","");
	int num = (int)d.val;
	double *check = (double *)malloc(sizeof(double)*(num + 1));
	if (check == NULL) execerror("out of space","");
	sp->u.arrptr = check;
	(sp->u.arrptr)[0] = num;
	return 2;
}

int arrassign()
{
	symbol *sp = (symbol *)*pc++;
	int args = (int)*pc++;

	double *check = (double *)malloc(sizeof(double)*(args+1));
	if (check == NULL) execerror("out of space","");
	sp->u.arrptr = check;
	(sp->u.arrptr)[0] = args;
	for (int i = args; i > 0; i--)
	{
		Datum d;
		d = pop();
		(sp->u.arrptr)[i] = d.val;
	}
	return 2;
}

int arrpush()
{
	symbol *sp = (symbol *)*pc++;
	if(sp->type != ARRAY) execerror("not an array",sp->name);
	Datum d = pop();
	Datum in = pop();
	if (!isinteger(in.val)) execerror("non integral index","");
	int index =(int)in.val + 1;
	if (index < 1 || index > (sp->u.arrptr)[0]) execerror("illegal reference","");
	(sp->u.arrptr)[index] = d.val;
	push(d);
	return 2;
}

int arrpop()
{
	symbol *sp = (symbol *)*pc++;
	if(sp->type != ARRAY) execerror("not an array",sp->name);
	Datum d = pop();
	if(!isinteger(d.val)) execerror("non integral index","");
	int index = (int)d.val + 1;
	if (index < 1 || index > (sp->u.arrptr)[0]) execerror("illegal reference","");
	Datum d1;
	d1.val = (sp->u.arrptr)[index];
	push(d1);
	return 2;
}

int arrlen()
{
	symbol *sp = (symbol *)*pc++;
	Datum d;
	d.val = (sp->u.arrptr)[0];
	push(d);
}
