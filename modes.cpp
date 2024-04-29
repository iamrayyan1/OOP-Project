#include <iostream>
//#include<conio.h>
//#include<dos.h>
#include <windows.h>
#include<time.h>

// Directories
#include "MainHeader.h"

using namespace std;


void modes() {

  easyClass eC;
  mediumClass mC;
  hardClass hc;

  setcursor(0,0);
  srand((unsigned)time(NULL));


    do {
    system("cls");
    system("color A");
    gotoxy(50,5); cout << " ------------------- ";
    gotoxy(50,6); cout << " |     CAR GAME    |";
    gotoxy(50,7); cout << " ------------------- ";
    gotoxy(50,9); cout << " 	EASY MODE    	";
    gotoxy(50,10); cout << " 	MEDIUM MODE	";
    gotoxy(50,11); cout << " 	LEGENDARY MODE (HARD)			";
    gotoxy(50,12); cout << " 	BACK			";
    gotoxy(50,14); cout << ">>> CHOICE:		";
    char op = getchar();

    switch(op) {
      case '1':
        eC.easyPlay();
        break;
      case '2':
        mC.mediumPlay();
        break;
      case '3':
        hc.hardPlay();
        break;
      case '4':
        getMenu();
        break;
      default:
        cout << "Invalid! Try again";
        Sleep(888);
        break;
    }

  } while (1);



}



















/*
  #include <iostream>
  #include <windows.h>
  #include <time.h>
  #include <thread>
  #include <chrono>

  // Directories
  #include "MainHeader.h"

  using namespace std;

  // Constants
  const int WIN_WIDTH = 80; // Assuming a standard console width
  const int SCREEN_WIDTH = WIN_WIDTH - 20; // Adjusted for the border
  const int SCREEN_HEIGHT = 25;

  // Classes declaration and implementation go here...

  void gotoxy(int x, int y) {
      COORD CursorPosition;
      CursorPosition.X = x;
      CursorPosition.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
  }

  void setcursor(bool visible, DWORD size) {
      CONSOLE_CURSOR_INFO lpCursor;
      lpCursor.bVisible = visible;
      lpCursor.dwSize = size;
      SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursor);
  }

  void Sleep(int milliseconds) {
      // Cross-platform sleep function implementation
      this_thread::sleep_for(chrono::milliseconds(milliseconds));
  }

  void modes() {
      easyClass eC;
      mediumClass mC;
      hardClass hc;

      setcursor(false, 0); // Hide cursor
      srand((unsigned)time(NULL));

      do {
          system("cls");
          system("color A");
          gotoxy(50, 5); cout << " ------------------- ";
          gotoxy(50, 6); cout << " |     CAR GAME    |";
          gotoxy(50, 7); cout << " ------------------- ";
          gotoxy(50, 9); cout << "  EASY MODE     ";
          gotoxy(50, 10); cout << "  MEDIUM MODE   ";
          gotoxy(50, 11); cout << "  LEGENDARY MODE (HARD)       ";
          gotoxy(50, 12); cout << "  BACK          ";
          gotoxy(50, 14); cout << ">>> CHOICE:     ";
          char op;
          cin >> op; // Use cin instead of getchar()

          switch (op) {
          case '1':
              eC.easyPlay();
              break;
          case '2':
              mC.mediumPlay();
              break;
          case '3':
              hc.hardPlay();
              break;
          case '4':
              getMenu();
              break;
          default:
              cout << "Invalid! Try again";
              Sleep(888);
              break;
          }

      } while (1);
  }

  int main() {
      modes();
      return 0;
  }




*/
