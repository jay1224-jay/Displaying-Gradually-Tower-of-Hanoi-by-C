#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdio.h>

#include "common.h"


int current_state;

int main() {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Display Tower of Hanoi");
    SetTargetFPS(60);

    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    int count = 0;
    char message[10];

    current_state = stateHomeScreen;

    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(WHITE);


            switch ( current_state ) {

                case statePause: 
                    ;
                    break;
                case statePlay:
                    ;
                    break;
                case stateHomeScreen:
                    gameHomeScreen();
                    break;
                case stateInit:
                    gameInit();
                    // current_state = statePause;
                    break;
                default:
                    printf("Unknown state found.\nState: %d\n", current_state);
            
            }



        EndDrawing();
    }


    CloseWindow();

    return 0;
}
