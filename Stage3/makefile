//make -n ->shows the compilation stages without compiling

OBJS = symbol.o init.o math.o hoc3.o

hoc3: $(OBJS)
	cc $(OBJS) -o hoc3

hoc.tab.c hoc.tab.h: hoc.y
	bison -d hoc.y

hoc3.o: hoc.tab.c hoc.h
	cc -c hoc.tab.c -o hoc3.o

init.o: init.c hoc.h hoc.tab.h 
	cc -c init.c -o init.o

symbol.o: symbol.c hoc.h hoc.tab.h
	cc -c symbol.c -o symbol.o

math.o: math.c
	cc -c math.c -o math.o

clean: 
	rm -f $(OBJS) hoc3 hoc.tab.c hoc.tab.h
