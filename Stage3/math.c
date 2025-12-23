#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include "hoc.h"

extern void execerror(const char *s, const char *t);
extern int errno;

double errcheck(double d, char *s)
{
	if (isnan(d)) execerror("input out of domain", s);
	return d;
}

double Log(double x)
{
	return errcheck(log(x),"log");
}

double Log10(double x)
{
	return errcheck(log10(x),"log10");
}

double Exp(double x)
{
	return errcheck(exp(x),"exp");
}

double Sqrt(double x)
{
	return errcheck(sqrt(x),"sqrt");
}

double Pow(double x, double y)
{
	return errcheck(pow(x,y),"pow");
}

double Integer(double x) //floor function
{
	return (double)(long)x;
}

double atan2(double y, double x)
{
	if (x == 0) execerror("division by 0","");
	symbol *sym = lookup("PI");
	return (180/sym->u.val)*atan(y/x);
}

double Rand()
{
	return (double)rand()/(double)RAND_MAX;
}
