

#include <stdio.h>
#include <stdlib.h>


/*

 s  m  d
 |  |  |
 _  =  _

*/

#define numberOfDisks 5
typedef struct {
    int number;
    char from;
    char to;
} step;

step move[1000];
int stepN = f(numberOfDisks), ind = 0;

void generateProgress(int n, char s, char m, char d) {
	if ( n == 1 ) {
        move[stepN-ind-1].number = n;
        move[stepN-ind-1].from = s;
        move[stepN-ind-1].to = d;
        ind++;
		return;
	}
    
	generateProgress(n-1, s, d, m); // move
    move[stepN-ind-1].number = n;
    move[stepN-ind-1].from   = s;
    move[stepN-ind-1].to     = d;
    ind++;
	generateProgress(n-1, m, s, d); // move
    move[stepN-ind-1].number = n;
    move[stepN-ind-1].from   = s;
    move[stepN-ind-1].to     = d;
	return;
}

/*
int main() {
	

    count = f(n);

    printf("%d\n", count);


    generateProgress(n, 'a', 'b', 'c');


    for ( int i = 0 ; i < f(n) ; ++i ) {
        printf("%d %c %c\n", move[i].number, move[i].from, move[i].to);
    }
	
    return 0;
	
}
*/

