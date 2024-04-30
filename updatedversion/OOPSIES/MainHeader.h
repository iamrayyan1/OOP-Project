#ifndef MAINHEADER_H
#define MAINHEADER_H
//#include "MainHeader.h"
#include<windows.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

// Global 

	static int enemyY[5];
	static int enemyX[5];
	static int enemyFlag[3];
	static int carPos = WIN_WIDTH / 2;
	static int score = 0;
	static const char car[4][4] = {' ', 'O', 'O', ' ',
                                	'O', '*', '*', 'O',
                                	' ', '*', '*', ' ',
                                	'O', '*', '*', 'O'};

  void modes();
  void gotoxy(int x, int y);
  void instructions();
  void setcursor(bool visible, DWORD size);
  void gameover();
  void getMenu();

class easyClass {

  public:
    static void easyPlay();
    static void drawEnemy(int ind);
    static void eraseEnemy(int ind);
    static void resetEnemy(int ind);
    static void drawBorder();		
    static int collision();
    static void updateScore();	  
    static void drawCar();
    static void eraseCar();
    static void genEnemy(int ind);			
};

class mediumClass {
  public:
    static void mediumPlay();
    static void drawEnemy(int ind);
    static void eraseEnemy(int ind);
    static void resetEnemy(int ind);
    static void drawBorder();		
    static int collision();
    static void updateScore();	  
    static void drawCar();
    static void eraseCar();
    static void genEnemy(int ind);

};

class hardClass {
  public:
    static void hardPlay();
    static void drawEnemy(int ind);
    static void eraseEnemy(int ind);
    static void resetEnemy(int ind);
    static void drawBorder();		
    static int  collision();
    static void updateScore();	  
    static void drawCar();
    static void eraseCar();
    static void genEnemy(int ind);

};









#endif
