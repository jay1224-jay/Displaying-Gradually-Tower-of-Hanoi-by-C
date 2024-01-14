#include "raylib.h"

#include "raygui.h"

#include <stdio.h>
#include <stdlib.h>

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

#define towerA 'a'
#define towerB 'b'
#define towerC 'c'

#define isStill(Disk) ( (abs(Disk.x - Disk.targetX) < 2) && (abs(Disk.y - Disk.targetY) < 2 ) )
#define numberOfDisks 4

rect disks[numberOfDisks];

const int diskMaxWidth = 200;

// double because we have to calculate the disk height as double
const int diskMaxHeight = 200;
const int diskBeginX = 100, diskBeginY = 200; // (width - diskMaxWidth)/2;
const double defaultXSpeed = 2, defaultYSpeed = 2;
const int diskCeilY = 100;


// 3 sticks
Color stickColor;
int stickWidth, stickHeight, stickBeginX, stickDistance, stickBeginY, firstDiskY;


int currentMovingDisk = 0, currentStep = 0, goMoving = 0, stepN, ind = 0,
    canGoNext = 1, waitForTop = 0;

step move[1000];

int f(int n) {
	if ( n == 1 ) return 1;
	return 2 * f(n-1) + 1;
}


void generateProgress(int n, char s, char m, char d) {
	if ( n == 1 ) {
        move[ind].number = n;
        move[ind].from = s;
        move[ind].to = d;
        ind++;
		return;
	}
    
	generateProgress(n-1, s, d, m); // move
    move[ind].number = n;
    move[ind].from   = s;
    move[ind].to     = d;
    ind++;
	generateProgress(n-1, m, s, d); // move
    move[ind].number = n;
    move[ind].from   = s;
    move[ind].to     = d;
	return;
}

void initTower(void) {
    // Initialization
    //

    for ( int i = 0 ; i < numberOfDisks ; ++i ) {
        disks[i].x = diskBeginX + (diskMaxWidth/2 - diskMaxWidth/2 * (i+1) / numberOfDisks);
        disks[i].y = diskBeginY + (diskMaxHeight  / numberOfDisks) * i;
        disks[i].width = diskMaxWidth * ( i+1 ) / numberOfDisks;
        disks[i].height = (double)diskMaxHeight / numberOfDisks;
        disks[i].color = BLUE; // (i%2) ? BLUE : SKYBLUE;
        disks[i].targetX = disks[i].x;
        disks[i].targetY = disks[i].y;
        disks[i].xSpeed = defaultXSpeed;
        disks[i].ySpeed = defaultYSpeed;
    }

    // sticks
    stickColor = BROWN;
    stickWidth = 10;
    stickHeight = 50 + diskMaxHeight;
    stickBeginX = disks[0].x + (disks[0].width - stickWidth)/2; // disks[0].x + stickWidth/2;
    stickBeginY = disks[0].y;
    stickDistance = \
        (WINDOW_WIDTH - (stickBeginX*2)) / 2;
    firstDiskY = disks[0].y;

    stepN = f(numberOfDisks);

}


void displayTower(void) {



    int backButtonWidth = 80, backButtonHeight = 50;
    if ( GuiButton((Rectangle){ WINDOW_WIDTH - backButtonWidth - 30, 
                                WINDOW_HEIGHT - backButtonHeight - 30,
                                backButtonWidth, 
                                backButtonHeight}, "Back") ) {
        current_state = stateHomeScreen;
        goMoving = 0;

    }

    if ( GuiButton((Rectangle){100, 500, 70, 40}, "Move") ) {

        goMoving = 1;

    }

    if ( goMoving ) {
        goMoving=0;
        canGoNext = 0;

        int stickI;

        // disks[move[currentStep].number-1].targetY = diskCeilY;

        if ( waitForTop == 1 )
            waitForTop = 1;
        else {
            switch (move[currentStep].to) {
            case towerA:
                stickI = 0;
                break;
            case towerB:
                stickI = 1;
                break;
            case towerC:
                stickI = 2;
                break;
            }

            // disks[move[currentStep].number-1].targetX = stickBeginX + (stickDistance*stickI);
        
            disks[move[currentStep].number-1].targetX = stickBeginX + (stickDistance*stickI) - (disks[move[currentStep].number-1].width)/2 + (stickWidth)/2;

            if ( currentStep < stepN-1 ) {
                ++currentStep;
                canGoNext = 0;
            }
        }


    }

    // move continuously
    if ( canGoNext == 0 && isStill(disks[move[currentStep-1].number-1]) && currentStep < stepN) {
        goMoving = 1;
        canGoNext = 1;
    }

    // Draw 3 sticks in center


    for ( int i = 0 ; i < 3 ; ++i ) {

        Vector2 vPos  = { stickBeginX + (stickDistance*i) , firstDiskY - 50 };
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
