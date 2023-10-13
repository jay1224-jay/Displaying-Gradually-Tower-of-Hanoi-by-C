#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b;
    scanf("%d %d", &a, &b);


    int (*board)[b] = malloc(sizeof(int) * a * b);

    for ( int i = 0 ; i < b ; ++i ) { 
        for ( int j = 0 ; j < a ; ++j ) 
            board[i][j] = i+j;
        printf("\n");
    }

    for ( int i = 0 ; i < b ; ++i ) { 
        for ( int j = 0 ; j < a ; ++j ) 
            printf("%d ", board[i][j]);
        printf("\n");
    }


    free(board);

    return 0;
}
