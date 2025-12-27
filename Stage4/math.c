//custom functions can be added here
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979323846
double Rand()
{
	return (double)rand()/(double)RAND_MAX;
}

double Atan(double p1)
{
	double p = atan(p1);
	return p*(180/PI);
}

double Atan2(double p1, double p2)
{
	double p = atan2(p1,p2);
	return p*(180/PI);
}
