#include "hoc.h"
#include "hoc.tab.h"
#include <math.h>
#include <stdlib.h>

extern double Log(), Log10(), Exp(), Sqrt(), Integer(), Rand();

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
	"atan",  atan,
	"ln",    Log,
	"log",   Log10,
	"exp",   Exp,
	"sqrt",  Sqrt,
	"int",   Integer,
	"abs",   fabs,
	0,0
};

static struct
{
	char *name;
	double (*func)();
} builtin2s[] =
{
	"atan2",	atan2,
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

void init()
{
	int i;
	symbol *s;
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










