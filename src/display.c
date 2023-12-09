#include "raylib.h"

#include "raygui.h"

#include <stdio.h>

#include "common.h"


typedef struct {
    double x;
    double y;
    double height;
    double width;

    // movement
    double targetX;
    double targetY;
    double xSpeed;
    double ySpeed;

    Color color;

} rect;

#define numberOfDisks 10

rect disks[numberOfDisks];
const int diskMaxWidth = 200;

// double because we have to calculate the disk height as double
const int diskMaxHeight = 200;
const int diskBeginX = 100, diskBeginY = 200; // (width - diskMaxWidth)/2;
const double defaultXSpeed = 2, defaultYSpeed = 2;


// 3 sticks
Color stickColor;
int stickWidth, stickHeight, stickBeginX, stickDistance, stickBeginY;

void initTower(void) {
    // Initialization
    //

    for ( int i = 0 ; i < numberOfDisks ; ++i ) {
        disks[i].x = diskBeginX + (diskMaxWidth/2 - diskMaxWidth/2 * (i+1) / numberOfDisks);
        disks[i].y = diskBeginY + (diskMaxHeight  / numberOfDisks) * i;
        disks[i].width = diskMaxWidth * ( i+1 ) / numberOfDisks;
        disks[i].height = (double)diskMaxHeight / numberOfDisks;
        disks[i].color = (i%2) ? BLUE : SKYBLUE;
        disks[i].targetX = disks[i].x;
        disks[i].targetY = disks[i].y;
        disks[i].xSpeed = defaultXSpeed;
        disks[i].ySpeed = defaultYSpeed;
    }
    // sticks
    stickColor = BROWN;
    stickWidth = disks[0].width - 10;
    stickHeight = 50 + diskMaxHeight;
    stickBeginX = disks[0].x + stickWidth/2;
    stickBeginY = disks[0].y;
    stickDistance = \
        (WINDOW_WIDTH - (stickBeginX*2)) / 2;
}

void displayTower(void) {



    int backButtonWidth = 80, backButtonHeight = 50;
    if ( GuiButton((Rectangle){ WINDOW_WIDTH - backButtonWidth - 30, 
                                WINDOW_HEIGHT - backButtonHeight - 30,
                                backButtonWidth, 
                                backButtonHeight}, "Back") ) {

        current_state = stateHomeScreen;

    }

    if ( GuiButton((Rectangle){100, 500, 70, 40}, "Move") ) {
        disks[0].targetX = 500;
    }


    // Draw 3 sticks in center


    for ( int i = 0 ; i < 3 ; ++i ) {

        Vector2 vPos  = { stickBeginX + (stickDistance*i) , disks[0].y - 50 };
        Vector2 vSize = {stickWidth, stickHeight};

        DrawRectangleV(vPos, vSize, stickColor);

    }
    
    // #define TEST
    #ifdef TEST
    printf("x: %.2f\n", disks[0].x);
    printf("y: %.2f\n", disks[0].y);
    printf("targetX: %.2f\n", disks[0].targetX);
    printf("targetY: %.2f\n", disks[0].targetY);
    printf("x speed: %.2f\n", disks[0].xSpeed);
    #endif


    // Check if a disk have to move to target posittion

    for ( int i = 0 ; i < numberOfDisks ; ++i ) {

        if ( disks[i].x != disks[i].targetX ) {
            if ( disks[i].x < disks[i].targetX ) {
                disks[i].x += disks[i].xSpeed;
            } else {
                disks[i].x -= disks[i].xSpeed;
            }
        }

        if ( disks[i].y != disks[i].targetY ) {
            if ( disks[i].y < disks[i].targetY ) {
                disks[i].y += disks[i].ySpeed;
            } else {
                disks[i].y -= disks[i].ySpeed;
            }
        }
    }


    // Draw disks
    for ( int i = 0 ; i < numberOfDisks ; ++i ) {

        rect disk = disks[i];

        Vector2 vPos = {disk.x, disk.y};
        Vector2 vSize = {disk.width, disk.height};
        DrawRectangleV(vPos, vSize, disk.color);

    }


}
