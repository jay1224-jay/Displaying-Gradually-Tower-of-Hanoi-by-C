#include "raylib.h"
#include "raygui.h"

#include <stdio.h>

#include "common.h"

void gameInit(void) {

    DrawText("Initializing the Tower of Hanoi", 100, 100, 30, BLACK);
    // printf("current state: %d\n", current_state);
    
    int backButtonWidth = 80, backButtonHeight = 50;
    if ( GuiButton((Rectangle){ WINDOW_WIDTH - backButtonWidth - 30, 
                                WINDOW_HEIGHT - backButtonHeight - 30,
                                backButtonWidth, 
                                backButtonHeight}, "Back") ) {

        current_state = stateHomeScreen;

    }

}
