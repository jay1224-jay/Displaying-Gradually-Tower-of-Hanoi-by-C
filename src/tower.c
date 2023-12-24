

#include <stdio.h>
int f(int n) {
	if ( n == 1 ) return 1;
	return 2 * f(n-1) + 1;
}
/*

 s  m  d
 |  |  |
 _  =  _

*/

typedef struct {
    int number;
    char from;
    char to;
} step;

int n = 3, count;
step * move;

void generateProgress(int n, char s, char m, char d) {
	if ( n == 1 ) {
        move[0][0] = n;
        move[0][1] = s;
        move[0][2] = d;
		return;
	}
    --count;
	progress(n-1, s, d, m); // move
    move[count].number = n;
    move[count].from   = s;
    move[count].to     = d;
	printf("move %d from %c to %c\n", n, s, d);
    --count;
	progress(n-1, m, s, d); // move
    move[count].number = n;
    move[count].from   = s;
    move[count].to     = d;
	printf("move %d from %c to %c\n", n, s, d);
	return;
}

int main() {
	

    count = f(n);

    move = (step)malloc(sizeof(step) * count);

    generateProgress();
	
    return 0;
	
}
