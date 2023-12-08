CC = gcc
LIBS = -lraylib -lm -lpthread -ldl
OBJS = display.o homeScreen.o init.o

a.out: $(OBJS) 
	$(CC) $(OBJS) $(LIBS)

display.o: display.c common.h
	$(CC) display.c -c

homeScreen.o: homeScreen.c common.h
	$(CC) homeScreen.c -c

init.o: init.c common.h
	$(CC) init.c -c

clean:
	rm *.o




