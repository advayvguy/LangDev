OBJS = symbol.o init.o math.o hoc5.o code.o

hoc4: $(OBJS)
	cc $(OBJS) -o hoc5

hoc.tab.c hoc.tab.h: hoc.y
	bison -d hoc.y

hoc5.o: hoc.tab.c hoc.h
	cc -c hoc.tab.c -o hoc5.o

init.o: init.c hoc.h hoc.tab.h 
	cc -c init.c -o init.o

symbol.o: symbol.c hoc.h hoc.tab.h
	cc -c symbol.c -o symbol.o

math.o: math.c
	cc -c math.c -o math.o

code.o: code.c hoc.h hoc.tab.h
	cc -c code.c -o code.o

clean: 
	rm -f $(OBJS) hoc5 hoc.tab.c hoc.tab.h
