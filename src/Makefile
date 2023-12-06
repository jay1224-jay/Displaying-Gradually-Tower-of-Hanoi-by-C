CC = gcc
LIBS = -lraylib -lm -lpthread -ldl
OBJS = display.o 

a.out: $(OBJS) 
	$(CC) $(OBJS) $(LIBS)

display.o: display.c display.h
	$(CC) display.c -c

clean:
	rm *.o




