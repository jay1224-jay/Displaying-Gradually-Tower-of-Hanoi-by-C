#include "raylib.h"

#include "raygui.h"

#include <stdio.h>

#include "common.h"


typedef struct {
    double x;
    double y;
    double height;
    double width;

    Color color;

    /*
     * If use int as the type, the height of the pyramid will not be consistent so it will shake in the center.
     * Using double like the example above solves the problem.

    int x;
    int y;
    int height;
    int width;

    */

} rect;

void displayTower(void) {



    int backButtonWidth = 80, backButtonHeight = 50;
    if ( GuiButton((Rectangle){ WINDOW_WIDTH - backButtonWidth - 30, 
                                WINDOW_HEIGHT - backButtonHeight - 30,
                                backButtonWidth, 
                                backButtonHeight}, "Back") ) {

        current_state = stateHomeScreen;

    }

    DrawTextB("Tower", 100, 200, 20, BLUE);

    // n:       how many disks you want
    // stop:    the maximum number of disks
    int n = 10;
    const int max_width = 150, width = 800;

    // double because we have to calculate the disk height as double
    const double max_height = 150;
    const int begin_x = 100; // (width - max_width)/2;
    rect disks[n]; 

    for ( int i = 0 ; i < n ; ++i ) {
        disks[i].x = begin_x + (max_width/2 - max_width/2 * (i+1) / n);
        disks[i].y = 200 + (max_height  / n) * i;
        disks[i].width = max_width * ( i+1 ) / n;
        disks[i].height = (double)max_height / n;
        disks[i].color = (i%2) ? BLUE : SKYBLUE;
    }


    for ( int i = 0 ; i < n ; ++i ) {
        rect disk = disks[i];

        Vector2 vPos = {disk.x, disk.y};
        Vector2 vSize = {disk.width, disk.height};
        DrawRectangleV(vPos, vSize, disk.color);

    }

}
