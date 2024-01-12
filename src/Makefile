CC = gcc
LIBS = -lraylib -lm -lpthread -ldl
OBJS = main.o display.o homeScreen.o

a.out: $(OBJS) 
	$(CC) $(OBJS) $(LIBS)

main.o: main.c common.h raygui.h
	$(CC) main.c -c

display.o: display.c common.h raygui.h
	$(CC) display.c -c

homeScreen.o: homeScreen.c common.h raygui.h
	$(CC) homeScreen.c -c
 
tower.o: tower.c common.h raygui.h
	$(CC) tower.c -c


clean:
	rm *.o

remake:
	rm *.o
	make


