
/*    
 *  tgl.h: Terminal Graphic Library header file
 *  Author: jay1224-jay(Github)
 *
 *  feature:
 *      1. set_board(int width, int height) 
 *      2. 
 *
 *
 *
*/

/* Test Width and Height char lengthh 
                                                                        7      8
12345678901234567890123456789012345678901234567890123456789012345678901234567890
================================================================================

*/



#include <stdio.h>
#include <stdlib.h>


// ratio = 16:9
// 16 * 5
#define DEFAULT_WIDTH  80 

// 9 * 5
#define DEFAULT_HEIGHT 45

#define DEFAULT_CHAR   '='



// char (*_board)[DEFAULT_HEIGHT];
char ** _board;

void int_swap(int *, int *);

void tgl_initBoard(void);
void tgl_setCharPosition(char, int, int);
void tgl_setCharHorizontalLine(char, int, int, int);
void tgl_displayBoard(void);

void int_swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void tgl_initBoard() {

    // Initialize board with DEFAULT_CHAR

    _board = (char**)malloc(sizeof(char) * DEFAULT_WIDTH * DEFAULT_HEIGHT);

    for ( int y = 0 ; y < DEFAULT_HEIGHT ; ++y )
        for ( int x = 0 ; x < DEFAULT_WIDTH ; ++x ) 
            _board[y][x] = DEFAULT_CHAR;

}

void tgl_setCharPosition(char ch, int x, int y) {

    // change character by given position in board

    _board[y][x] = ch;

}

void tgl_setCharHorizontalLine(char ch, int x1, int x2, int y) {

    // change character by given y and a range of x 

    /*  example:
     *  
     *  OOOOOO
     *
     *  // after call
     *    2 3
     *  OOXXXO
     *
     *
     *  */

    if ( x1 > x2 ) 
        int_swap(&x1, &x2);
    
    for ( int x = x1 ; x <= x2 && (x > 0 && x < DEFAULT_WIDTH)  ; ++x )
        _board[y][x] = ch;

}

void tgl_displayBoard() {

    for ( int y = 0 ; y < DEFAULT_HEIGHT ; ++y )
        for ( int x = 0 ; x < DEFAULT_WIDTH ; ++x ) 
            printf("%c", _board[y][x]);

}

