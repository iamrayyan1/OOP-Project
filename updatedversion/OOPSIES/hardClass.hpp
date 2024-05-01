#ifndef HARDCLASS_HPP
#define HARDCLASS_HPP

#include <iostream>
#include <windows.h>
#include <ctime>

// Directories
#include "MainHeader.h"

using namespace std;

//static int carPos = WIN_WIDTH / 2;
//static int score = 0;
//static const char car[4][4] = {' ', '^', '^', ' ',
//                                '[', 'Z', 'Z', ']',
//                                ' ', 'Z', 'Z', ' ',
//                                '[', 'Z', 'Z', ']'};
//static int enemyY[5];
//static int enemyX[5];
//static int enemyFlag[3];

//void gotoxy(int x, int y) {
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}


void hardClass::genEnemy(int ind) {
    enemyX[ind] = 17 + rand() % (33);
}

void hardClass::drawEnemy(int ind) {
    if (enemyFlag[ind] == true) {
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "|  |";
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "UUUU";
        gotoxy(enemyX[ind], enemyY[ind] + 1);
        cout << " UU ";
        gotoxy(enemyX[ind], enemyY[ind] + 2);
        cout << "UUUU";
        gotoxy(enemyX[ind], enemyY[ind] + 3);
        cout << " vv ";
    }
}

void hardClass::eraseEnemy(int ind) {
    if (enemyFlag[ind] == true) {
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "     ";
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "     ";
        gotoxy(enemyX[ind], enemyY[ind] + 1);
        cout << "     ";
        gotoxy(enemyX[ind], enemyY[ind] + 2);
        cout << "     ";
        gotoxy(enemyX[ind], enemyY[ind] + 3);
        cout << "     ";
    }
}

void hardClass::resetEnemy(int ind) {
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void hardClass::drawBorder() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < 17; j++) {
            gotoxy(0 + j, i);
            cout << "V";
            gotoxy(WIN_WIDTH - j, i);
            cout << "V";
        }
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        gotoxy(SCREEN_WIDTH, i);
        cout << "V";
    }
}

int hardClass::collision() {
    if ((enemyY[0]) + 4 >= 23) {
        if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9) {
            return 1;
        }
    }
    return 0;
}

void hardClass::updateScore() {
    gotoxy(WIN_WIDTH + 7, 5);
    cout << "Score: " << score << endl;
}

void hardClass::drawCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gotoxy(j + carPos, i + 22);
            cout << car[i][j];
        }
    }
}

void hardClass::eraseCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gotoxy(j + carPos, i + 22);
            cout << " ";
        }
    }
}

void hardClass::hardPlay() {
    system("color 6");
    carPos = -1 + WIN_WIDTH / 2;
    score = 0;
    for (int i = 0; i < 3; ++i)
        enemyFlag[i] = false;
    for (int i = 0; i < 2; ++i)
        enemyY[i] = 1;

    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);
    genEnemy(2);
    genEnemy(3);

    gotoxy(WIN_WIDTH + 7, 2);
    cout << "THE CAR GAME";
    gotoxy(WIN_WIDTH + 6, 4);
    cout << "---------";
    gotoxy(WIN_WIDTH + 7, 12);
    cout << "CONTROLS:";
    gotoxy(WIN_WIDTH + 7, 13);
    cout << "---------";
    gotoxy(WIN_WIDTH + 2, 14);
    cout << "A - Left";
    gotoxy(WIN_WIDTH + 2, 15);
    cout << "D - Right";
    gotoxy(WIN_WIDTH + 2, 16);
    cout << "E - Exit";

    gotoxy(18, 5);
    cout << "Press any key to begin";
    cin.get();
    gotoxy(18, 5);
    cout << "                        ";

    while (1) {
        if (GetAsyncKeyState('A') & 0x8000) {
            // Change speed of left
            if (carPos > 18)
                carPos -= 4;
        }
        if (GetAsyncKeyState('D') & 0x8000) {
            // Change speed of right
            if (carPos < 50)
                carPos += 4;
        }
        if (GetAsyncKeyState('E') & 0x8000) {
            // Exit
            return;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            // Exit
            return;
        }

        drawCar();
        for (int i = 0; i < 4; ++i)
            drawEnemy(i);

        if (collision() == 1) {
            gameover();
            return;
        }
        Sleep(50);
        eraseCar();
        for (int i = 0; i < 4; ++i)
            eraseEnemy(i);

        for (int i = 0; i < 4; ++i) {
            if (enemyY[i] == 10) {
                if (!enemyFlag[i])
                    enemyFlag[i] = true;
                enemyY[i] += 3;
            }

            if (enemyY[i] > SCREEN_HEIGHT - 4) {
                resetEnemy(i);
                score++;
                updateScore();
            }
        }
    }
}


#endif