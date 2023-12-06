#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdio.h>

#include "display.h"


int main() {

    InitWindow(WIDTH, HEIGHT, "Display Tower of Hanoi");
    SetTargetFPS(60);

    int count = 0;
    char message[10] ;

    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(BLACK);

            if ( GuiButton( (Rectangle){200, 200, 50, 20}, "Click me" ) ) {
                ++count;
                sprintf(message, "%d times", count);
                printf("click\n");
            }
            DrawText(message, 200, 260, 20, WHITE) ;
            DrawText("Hello from raylib", 100, 100, 30, BLUE);

        EndDrawing();
    }


    CloseWindow();

    return 0;
}
