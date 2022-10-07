EXECS = arraylist c

all: ${EXECS}

generatearraylist: arraylist.o
	gcc ${FLAGS} -o $@ $^ -lm

arraylist.o: arraylist.c arraylist.h
	gcc ${FLAGS} -c $<

clean:
	rm -rf *.o ${EXECS}
