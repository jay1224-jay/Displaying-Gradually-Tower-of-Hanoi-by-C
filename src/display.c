#include "raylib.h"
#include <stdio.h>

#include "display.h"


int main() {

    InitWindow(WIDTH, HEIGHT, "Display Tower of Hanoi");
    

    while (!WindowShouldClose()) {

        BeginDrawing();

            DrawText("Hello from raylib", 100, 100, 30, BLUE);

        EndDrawing();
    }


    CloseWindow();

    return 0;
}
