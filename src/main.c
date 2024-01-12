#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdio.h>

#include "common.h"

#define towerA 'a'
#define towerB 'b'
#define towerC 'c'

int current_state;
Font myfont;

int main() {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Display Tower of Hanoi");
    SetTargetFPS(60);


    // myfont = LoadFontEx("resources/Consolas.ttf", 128, 0, 250);
    myfont = LoadFont("resources/Consolas.ttf");

    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetFont(myfont);

    int count = 0, towerN = 3;
    char message[10];
    step move[1000];

    current_state = stateHomeScreen;

    initTower();
    generateProgress(towerN, towerA, towerB, towerC);
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
