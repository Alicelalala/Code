CC = gcc
CFLAGS = -I./thirdpart/include -DTEST_CASE -std=c11 -Wall -g
OBJS = main.o newton.o binary_search.o

.PHONY : clean

a.out : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) thirdpart/libs/libtest.a

main.o : main.c
		$(CC) -c $(CFLAGS) main.c


