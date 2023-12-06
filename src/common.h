

#ifndef COMMON_H
#define COMMON_H

enum {  statePause = 0, 
        statePlay,
        stateHomeScreen,
        stateInit // initialize the tower
};

extern int current_state;


void gameHomeScreen(void);
void gameInit(void);


#endif
