#include <iostream>
#include <windows.h>
#include <ctime>

#include "MainHeader.h"

using namespace std;

static int carPos = WIN_WIDTH / 2;
static int score = 0;
static const char car[4][4] = {' ', '�', '�', ' ',
                               '�', '*', '*', '�',
                               ' ', '*', '*', ' ',
                               '�', '*', '*', '�'};
static int enemyY[5];
static int enemyX[5];
static int enemyFlag[3];

void easyClass::genEnemy(int ind) {
    enemyX[ind] = 17 + rand() % (33);
}

void easyClass::drawEnemy(int ind) {
    if (enemyFlag[ind] == true) {
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "|  |";
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "�**�";
        gotoxy(enemyX[ind], enemyY[ind] + 1);
        cout << " ** ";
        gotoxy(enemyX[ind], enemyY[ind] + 2);
        cout << "�**�";
        gotoxy(enemyX[ind], enemyY[ind] + 3);
        cout << " ** ";
    }
}

void easyClass::eraseEnemy(int ind) {
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

void easyClass::resetEnemy(int ind) {
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void easyClass::drawBorder() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < 17; j++) {
            gotoxy(0 + j, i);
            cout << "�";
            gotoxy(WIN_WIDTH - j, i);
            cout << "�";
        }
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        gotoxy(SCREEN_WIDTH, i);
        cout << "�";
    }
}

int easyClass::collision() {
    if ((enemyY[0]) + 4 >= 23) {
        if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9) {
            return 1;
        }
    }
    return 0;
}

void easyClass::updateScore() {
    gotoxy(WIN_WIDTH + 7, 5);
    cout << "Score: " << score << endl;
}

void easyClass::drawCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gotoxy(j + carPos, i + 22);
            cout << car[i][j];
        }
    }
}

void easyClass::eraseCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gotoxy(j + carPos, i + 22);
            cout << " ";
        }
    }
}

void easyClass::easyPlay() {
    carPos = -1 + WIN_WIDTH / 2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

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
    cin.ignore(); // Ignore any previous input in the buffer
    cin.get();    // Wait for user input
    gotoxy(18, 5);
    cout << "                        ";

    while (1) {
        if (GetAsyncKeyState('A') & 0x8000) {
            if (carPos > 18)
                carPos -= 4;
        }

        if (GetAsyncKeyState('D') & 0x8000) {
            if (carPos < 50)
                carPos += 4;
        }

        if (GetAsyncKeyState('E') & 0x8000) {
            getMenu();
            break;
        }

        drawCar();
        drawEnemy(0);
        drawEnemy(1);
        if (collision() == 1) {
            gameover();
            return;
        }
        Sleep(50);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if (enemyY[0] == 10)
            if (enemyFlag[1] == 0)
                enemyFlag[1] = 1;

        if (enemyFlag[0] == 1)
            enemyY[0] += 1;

        if (enemyFlag[1] == 1)
            enemyY[1] += 1;

        if (enemyY[0] > SCREEN_HEIGHT - 4) {
            resetEnemy(0);
            score++;
            updateScore();
        }
        if (enemyY[1] > SCREEN_HEIGHT - 4) {
            resetEnemy(1);
            score++;
            updateScore();
        }
    }
}
