

#include <stdio.h>
#include <stdlib.h>


int f(int n) {
	if ( n == 1 ) return 1;
	return 2 * f(n-1) + 1;
}
/*

 s  m  d
 |  |  |
 _  =  _

*/


step move[1000];

void generateProgress(int n, char s, char m, char d) {
	if ( n == 1 ) {
        move[count-ind-1].number = n;
        move[count-ind-1].from = s;
        move[count-ind-1].to = d;
        ind++;
		return;
	}
    
	generateProgress(n-1, s, d, m); // move
    move[count-ind-1].number = n;
    move[count-ind-1].from   = s;
    move[count-ind-1].to     = d;
    ind++;
	generateProgress(n-1, m, s, d); // move
    move[count-ind-1].number = n;
    move[count-ind-1].from   = s;
    move[count-ind-1].to     = d;
	return;
}

int main() {
	

    count = f(n);

    printf("%d\n", count);


    generateProgress(n, 'a', 'b', 'c');


    for ( int i = 0 ; i < f(n) ; ++i ) {
        printf("%d %c %c\n", move[i].number, move[i].from, move[i].to);
    }
	
    return 0;
	
}

