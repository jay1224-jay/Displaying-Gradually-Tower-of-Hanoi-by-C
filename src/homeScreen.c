#include "raylib.h"
#include "raygui.h"

#include <stdio.h>
#include "common.h"


void gameHomeScreen(void) {

    int startButtonWidth = 80, startButtonHeight = 50; 

    if ( GuiButton( (Rectangle){WINDOW_WIDTH/2 - startButtonWidth/2, WINDOW_HEIGHT/2 - startButtonHeight/2, startButtonWidth, startButtonHeight},  "Start" ) ) {
        current_state = stateInit;
    }


}
