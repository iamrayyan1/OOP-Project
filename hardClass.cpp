#include <iostream>
#include <windows.h>
#include <time.h>

// Directories
#include "MainHeader.h"

using namespace std;

static const int WIN_WIDTH = 80; // Assuming a standard console width
static const int SCREEN_WIDTH = 80; // Assuming a standard console width
static const int SCREEN_HEIGHT = 25; // Assuming a standard console height

class hardClass {
private:
    int carPos;
    int score;
    const char car[4][4] = {{' ', '^', '^', ' '},
                            {'[', '�', '�', ']'},
                            {' ', '�', '�', ' '},
                            {'[', '�', '�', ']'}};
    int enemyY[5];
    int enemyX[5];
    bool enemyFlag[3];

    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void genEnemy(int ind) {
        enemyX[ind] = 17 + rand() % (33);
    }

    void drawEnemy(int ind) {
        if (enemyFlag[ind]) {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "|  |";
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "�UU�";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " �� ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "����";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " vv ";
        }
    }

    void eraseEnemy(int ind) {
        if (enemyFlag[ind]) {
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

    void resetEnemy(int ind) {
        eraseEnemy(ind);
        enemyY[ind] = 1;
        genEnemy(ind);
    }

    void drawBorder() {
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

    int collision() {
        if ((enemyY[0]) + 4 >= 23) {
            if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9) {
                return 1;
            }
        }
        return 0;
    }

    void updateScore() {
        gotoxy(WIN_WIDTH + 7, 5);
        cout << "Score: " << score << endl;
    }

    void drawCar() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                gotoxy(j + carPos, i + 22);
                cout << car[i][j];
            }
        }
    }

    void eraseCar() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                gotoxy(j + carPos, i + 22);
                cout << " ";
            }
        }
    }

public:
    hardClass() : carPos(WIN_WIDTH / 2), score(0) {
        for (int i = 0; i < 3; ++i)
            enemyFlag[i] = false;
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

};

int main() {
    hardClass game;
    game.hardPlay();
    return 0;
}

