#include <stdio.h>

#include "tgl.h"

int main(int argc, char* argv[]) {

    tgl_initBoard();

    tgl_displayBoard();

    free(_board);

    return 0;
}
