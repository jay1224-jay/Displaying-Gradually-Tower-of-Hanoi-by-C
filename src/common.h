

#ifndef COMMON_H
#define COMMON_H

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

enum {  statePause = 0, 
        statePlay,
        stateHomeScreen,
        stateInit // initialize the tower
};

typedef struct {
    int number;
    char from;
    char to;
} step;

extern int current_state;
extern Font myfont;    // Global variable, initialize at beginning.


void gameHomeScreen(void);
void displayTower(void);
void initTower(void);

void DrawTextB(const char* msg, int x, int y, int fontSize, Color color);

void generateProgress(int, char, char, char);
extern step move[1000];
extern int towerN;


#endif
