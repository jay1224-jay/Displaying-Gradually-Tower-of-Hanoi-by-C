#include <stdio.h>

#include "common.h"

int main(int argc, char* argv[]) {

    printf("hello world\n");

    char m[HEIGHT][WIDTH];

    for ( int i = 0 ; i < HEIGHT ; ++i ) {
        for ( int j = 0 ; j < WIDTH ; ++j ) {
            m[i][j] = (65 + i * j);
        }
    }
    draw(m, WIDTH, HEIGHT);

    printf("draw() function worked successfully!\n");



    return 0;
}
