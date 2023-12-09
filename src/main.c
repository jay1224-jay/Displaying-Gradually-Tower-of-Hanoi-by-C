#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdio.h>

#include "common.h"


int current_state;
Font myfont;

int main() {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Display Tower of Hanoi");
    SetTargetFPS(60);


    // myfont = LoadFontEx("resources/Consolas.ttf", 128, 0, 250);
    myfont = LoadFont("resources/Consolas.ttf");

    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    int count = 0;
    char message[10];

    current_state = stateHomeScreen;

    initTower();
    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(LIGHTGRAY);


            switch ( current_state ) {

                case statePause: 
                    ;
                    break;
                case statePlay:
                    displayTower();
                    break;
                case stateHomeScreen:
                    gameHomeScreen();
                    break;
                default:
                    printf("Unknown state found.\nState: %d\n", current_state);
            
            }



        EndDrawing();
    }


    CloseWindow();

    return 0;
}


void DrawTextB(const char *text, int posX, int posY, int fontSize, Color color)
{
    DrawTextEx(myfont, text, (Vector2){ posX, posY }, fontSize, 1, color);
}
