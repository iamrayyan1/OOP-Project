// #include <iostream>
// #include <windows.h>
// #include <time.h>

// // Directories
// #include "MainHeader.h"

// using namespace std;

// const int WIN_WIDTH = 80;
// const int SCREEN_WIDTH = 80;
// const int SCREEN_HEIGHT = 25;

// class easyMode {
// public:
//     easyMode();
//     void genEnemy(int ind);
//     void gotoxy(int x, int y);
//     void drawEnemy(int ind);
//     void eraseEnemy(int ind);
//     void resetEnemy(int ind);
//     void setcursor(bool visible, DWORD size);
//     void drawBorder();
//     void collision();
//     void gameover();
//     void updateScore();
//     void instructions();
//     void drawCar();
//     void eraseCar();
//     void easyModeFunc();

// private:
//     HANDLE console;
//     COORD CursorPosition;
//     int carPos;
//     int score;
//     static const char car[4][4];
//     int enemyY[5];
//     int enemyX[5];
//     int enemyFlag[3];
// };

// const char easyMode::car[4][4] = {
//     {' ', '�', '�', ' '},
//     {'�', '*', '*', '�'},
//     {' ', '*', '*', ' '},
//     {'�', '*', '*', '�'}
// };

// easyMode::easyMode() {
//     console = GetStdHandle(STD_OUTPUT_HANDLE);
//     carPos = WIN_WIDTH / 2;
//     score = 0;
// }

// void easyMode::genEnemy(int ind) {
//     enemyX[ind] = 17 + rand() % (33);
// }

// void easyMode::gotoxy(int x, int y) {
//     CursorPosition.X = x;
//     CursorPosition.Y = y;
//     SetConsoleCursorPosition(console, CursorPosition);
// }

// void easyMode::drawEnemy(int ind) {
//     if (enemyFlag[ind] == true) {
//         gotoxy(enemyX[ind], enemyY[ind]);
//         cout << "|  |";
//         gotoxy(enemyX[ind], enemyY[ind]);
//         cout << "�**�";
//         gotoxy(enemyX[ind], enemyY[ind] + 1);
//         cout << " ** ";
//         gotoxy(enemyX[ind], enemyY[ind] + 2);
//         cout << "�**�";
//         gotoxy(enemyX[ind], enemyY[ind] + 3);
//         cout << " ** ";
//     }
// }

// void easyMode::eraseEnemy(int ind) {
//     if (enemyFlag[ind] == true) {
//         gotoxy(enemyX[ind], enemyY[ind]);
//         cout << "     ";
//         gotoxy(enemyX[ind], enemyY[ind]);
//         cout << "     ";
//         gotoxy(enemyX[ind], enemyY[ind] + 1);
//         cout << "     ";
//         gotoxy(enemyX[ind], enemyY[ind] + 2);
//         cout << "     ";
//         gotoxy(enemyX[ind], enemyY[ind] + 3);
//         cout << "     ";
//     }
// }

// void easyMode::resetEnemy(int ind) {
//     eraseEnemy(ind);
//     enemyY[ind] = 1;
//     genEnemy(ind);
// }

// void easyMode::setcursor(bool visible, DWORD size) {
//     if (size == 0)
//         size = 20;

//     CONSOLE_CURSOR_INFO lpCursor;
//     lpCursor.bVisible = visible;
//     lpCursor.dwSize = size;
//     SetConsoleCursorInfo(console, &lpCursor);
// }

// void easyMode::drawBorder() {
//     for (int i = 0; i < SCREEN_HEIGHT; i++) {
//         for (int j = 0; j < 17; j++) {
//             gotoxy(0 + j, i);
//             cout << "�";
//             gotoxy(WIN_WIDTH - j, i);
//             cout << "�";
//         }
//     }

//     for (int i = 0; i < SCREEN_HEIGHT; i++) {
//         gotoxy(SCREEN_WIDTH, i);
//         cout << "�";
//     }
// }

// void easyMode::collision() {
//     if ((enemyY[0]) + 4 >= 23) {
//         if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9) {
//             return 1;
//         }
//     }
//     return 0;
// }

// void easyMode::gameover() {
//     system("cls");
//     cout << "it's over.";
//     cin.ignore();
//     cin.get();
// }

// void easyMode::updateScore() {
//     gotoxy(WIN_WIDTH + 7, 5);
//     cout << "Score: " << score << endl;
// }

// void easyMode::instructions() {
//     system("cls");
//     cout << "Avoid cars, A = left, d = right, escape = exit" << endl;
//     cout << "Press any key to continue";
//     cin.ignore();
//     cin.get();
// }

// void easyMode::drawCar() {
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             gotoxy(j + carPos, i + 22);
//             cout << car[i][j];
//         }
//     }
// }

// void easyMode::eraseCar() {
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             gotoxy(j + carPos, i + 22);
//             cout << " ";
//         }
//     }
// }

// void easyMode::easyModeFunc() {
//     carPos = -1 + WIN_WIDTH / 2;
//     score = 0;
//     enemyFlag[0] = 1;
//     enemyFlag[1] = 0;
//     enemyY[0] = enemyY[1] = 1;

//     system("cls");
//     drawBorder();
//     updateScore();
//     genEnemy(0);
//     genEnemy(1);

//     gotoxy(WIN_WIDTH + 7, 2);
//     cout << "THE CAR GAME";
//     gotoxy(WIN_WIDTH + 6, 4);
//     cout << "---------";
//     gotoxy(WIN_WIDTH + 7, 12);
//     cout << "CONTROLS:";
//     gotoxy(WIN_WIDTH + 7, 13);
//     cout << "---------";
//     gotoxy(WIN_WIDTH + 2, 14);
//     cout << "A Key - Left";
//     gotoxy(WIN_WIDTH + 2, 15);
//     cout << "D Key - Right";

//     gotoxy(18, 5);
//     cout << "Press any key to begin";
//     cin.ignore();
//     gotoxy(18, 5);
//     cout << "                        ";

//     while (1) {
//         if (GetAsyncKeyState('A') & 0x8000) {
//             // Change speed of left
//             if (carPos > 18)
//                 carPos -= 4;
//         }
//         if (GetAsyncKeyState('D') & 0x8000) {
//             // Change speed of right
//             if (carPos < 50)
//                 carPos += 4;
//         }
//         if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
//             break;
//         }

//         drawCar();
//         drawEnemy(0);
//         drawEnemy(1);
//         if (collision() == 1) {
//             gameover();
//             return;
//         }
//         Sleep(50);
//         eraseCar();
//         eraseEnemy(0);
//         eraseEnemy(1);

//         if (enemyY[0] == 10)
//             if (enemyFlag[1] == 0)
//                 enemyFlag[1] = 1;

//         if (enemyFlag[0] == 1)
//             enemyY[0] += 1;

//         if (enemyFlag[1] == 1)
//             enemyY[1] += 1;

//         if (enemyY[0] > SCREEN_HEIGHT - 4) {
//             resetEnemy(0);
//             score++;
//             updateScore();
//         }
//         if (enemyY[1] > SCREEN_HEIGHT - 4) {
//             resetEnemy(1);
//             score++;
//             updateScore();
//         }
//     }
// }


