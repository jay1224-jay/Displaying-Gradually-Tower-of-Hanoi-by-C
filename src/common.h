

#ifndef COMMON_H
#define COMMON_H

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 500

enum {  statePause = 0, 
        statePlay,
        stateHomeScreen,
        stateInit // initialize the tower
};

extern int current_state;
extern Font myfont;    // Global variable, initialize at beginning.


void gameHomeScreen(void);
void displayTower(void);

void DrawTextB(const char* msg, int x, int y, int fontSize, Color color);

#endif
