hoc3				: symbol.o init.o math.o hoc3.o
	cc symbol.o init.o math.o hoc3.o -o hoc3

hoc.tab.h 	: hoc.y
	bison -d hoc.y

init.o    	: hoc.tab.h hoc.h init.c
	cc -c init.c -o init.o

symbol.o 		: hoc.tab.h hoc.h symbol.c
	cc -c symbol.c -o symbol.o

hoc3.o			: hoc.tab.c
	cc -c hoc.tab.c -o hoc3.o
	rm hoc.tab.c & rm hoc.tab.h

math.o			:math.c hoc.h
	cc -c math.c -o math.o
