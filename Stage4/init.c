#include "hoc.h"
#include "hoc.tab.h"
#include <math.h>
#include <stdlib.h>

extern double Rand(), Atan(double p1), Atan2(double p1, double p2); 
extern double execerror(const char *s, const char *t);
extern void makebufs();

extern int sizes;
extern int sizep;

static struct 
{
	char *name;
	double cval;
} consts[] = 
{
	"PI",    3.14159265358979323846,
	"E",     2.71828182845904523536,
	"GAMMA", 0.57721566490153286060,
	"DEG",  57.29577951308232087680,
	"PHI",   1.61803398874989484820,
	0,0
};

static struct
{
	char *name;
	double (*func)();
} builtins[] = 
{
	"sin", 	 sin,
	"cos", 	 cos,
	"atan",  Atan,
	"ln",    log,
	"log",   log10,
	"exp",   exp,
	"sqrt",  sqrt,
	"int",   floor,
	"abs",   fabs,
	0,0
};

static struct
{
	char *name;
	double (*func)();
} builtin2s[] =
{
	"atan2", Atan2,
	0,0
};

static struct
{
	char *name;
	double (*func)();
} builtin0s[] =
{
	"rand", Rand,
	0,0
};

void echeck(double val)
{
	if (isnan(val)) execerror("arugments out of domain","");
	if (isinf(val)) execerror("function out of range","");
}
	

Datum dispatch(Datum p1, Datum p2, symbol *s)
{
	Datum ans;
	if (s->type == BLTIN0)
	{
		ans.val = (s->u.ptr)();
	}
	else if (s->type == BLTIN)
	{
		ans.val = (s->u.ptr)(p1.val);
	}
	else if (s->type == BLTIN2)
	{
		ans.val = (s->u.ptr)(p1.val,p2.val);
	}
	echeck(ans.val);
	return ans;
}

void init()
{
	makebufs();
	int i;
	symbol *s;
	install("_",VAR,0.0);
	for (i = 0; consts[i].name; i++)
	{
		install(consts[i].name,CNST,consts[i].cval);
	}
	for (i = 0; builtins[i].name; i++)
	{
		s = install(builtins[i].name, BLTIN, 0.0);
		s->u.ptr = builtins[i].func;
	}
	for (i = 0; builtin2s[i].name; i++)
	{
		s = install(builtin2s[i].name, BLTIN2, 0.0);
		s->u.ptr = builtin2s[i].func;
	}
	for (i = 0; builtin2s[i].name; i++)
	{
		s = install(builtin0s[i].name, BLTIN0, 0.0);
		s->u.ptr = builtin0s[i].func;
	}
}
