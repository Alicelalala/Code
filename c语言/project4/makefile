CC = gcc
CFLAGS = -I./thirdpart/include -DTEST_CASE -std=c11 -Wall -g
OBJS = main.o dicsearch.o newton.o

.PHONY: clean

a.out : $(OBJS)
	    $(CC) $(CFLAGS) $(OBJS) thirdpart/libs/libtest.a
		    
main.o : main.c
	    $(CC) -c $(CFLAGS) main.c

dicsearch.o : dicsearch.c dicsearch.h
	    $(CC) -c $(CFLAGS) dicsearch.c

newton.o : newton.c newton.h
	    $(CC) -c $(CFLAGS) newton.c -lm
clean:
	    rm -rf *.o a.out 
