
#include <stdio.h>

#include "common.h"

void draw( char map[][WIDTH], int width, int height )
{
    for ( int i = 0 ; i < height ; ++i ) {
        for ( int j = 0 ; j < width ; ++j ) {
            printf("%c ", map[i][j] + 32 );
        }
        printf("\n");
    }


    // done
}
