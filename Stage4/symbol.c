#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hoc.h"
#include "hoc.tab.h"

static symbol *root = NULL;
extern void execerror(char *s, char *t);

void *emalloc(int size)
{
	void *allocheck = malloc(size);
	if (allocheck == NULL) execerror("memory limit exceeded", "");
	return allocheck;
}

symbol *install(char *s, int t, double val)
{
	symbol *sp;
	sp = emalloc(sizeof(symbol));
	sp->name = emalloc(strlen(s) + 1);
	strcpy(sp->name, s);
	sp->type = t;
	sp->u.val = val;
	sp->next = root;
	root = sp;
	return sp;
}

symbol *lookup(char *s)
{
	symbol *i;
	for(i = root; i != NULL; i = i->next)
	{
		if(strcmp(i->name,s) == 0) return i;
	}
	return NULL;
}
