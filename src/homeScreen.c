#include "raylib.h"
// 
// #define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdio.h>
#include "common.h"


void gameHomeScreen(void) {

    if ( GuiButton( (Rectangle){200, 200, 80, 50}, "Start" ) ) {
        current_state = stateInit;
    }

}
