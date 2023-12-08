#include "raylib.h"
#include "raygui.h"

#include <stdio.h>
#include "common.h"

char title[25] = "Display Tower of Hanoi";
char author[20] = "Author: Jay Wang";

void gameHomeScreen(void) {

    int startButtonWidth = 80, startButtonHeight = 50; 

    if ( GuiButton( (Rectangle){WINDOW_WIDTH/2 - startButtonWidth/2, WINDOW_HEIGHT/2 - startButtonHeight/2, startButtonWidth, startButtonHeight},  "Start" ) ) {
        current_state = statePlay;
    }


    DrawTextB(title, WINDOW_WIDTH/2 - 200, WINDOW_HEIGHT/2 + 50, 35, BLACK);
    DrawTextB(author, WINDOW_WIDTH/2 - 200, WINDOW_HEIGHT/2 + 50 + 50, 30, BLACK);

    // printf("text width: %d\n", (title));


}

