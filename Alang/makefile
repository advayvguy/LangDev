OBJS = symbol.o init.o math.o hoc6.o code.o

hoc6: $(OBJS)
	cc $(OBJS) -o hoc6

hoc.tab.c hoc.tab.h: hoc.y
	bison -d hoc.y

hoc6.o: hoc.tab.c hoc.h
	cc -c -g -O0 hoc.tab.c -o hoc6.o

init.o: init.c hoc.h hoc.tab.h 
	cc -c -g -O0 init.c -o init.o

symbol.o: symbol.c hoc.h hoc.tab.h
	cc -c  -g -O0 symbol.c -o symbol.o

math.o: math.c
	cc -c  -g -O0 math.c -o math.o

code.o: code.c hoc.h hoc.tab.h
	cc -c  -g -O0 code.c -o code.o

clean: 
	rm -f $(OBJS) hoc6 hoc.tab.c hoc.tab.h
