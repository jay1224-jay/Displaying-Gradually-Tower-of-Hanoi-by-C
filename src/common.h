

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


void gameHomeScreen(void);
void gameInit(void);


#endif
