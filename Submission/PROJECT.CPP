#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;


#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);  
COORD CursorPosition;  

void modes();
int main();

int enemyY[3];  
int enemyX[3];  
int enemyFlag[3]; 

int carPos = WIN_WIDTH/2;  
int score = 0; 

// static const char car[4][4] = {' ', 'O', 'O', ' ',
//                             	'O', '*', '*', 'O',
//                             	' ', '*', '*', ' ',
//                             	'O', '*', '*', 'O'};

void gotoxy(int x, int y){  
    CursorPosition.X = x;  
    CursorPosition.Y = y;  
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

// void gameover(){  
//     system("cls");  
//     cout<<endl;  
//     cout<<"\t\t--------------------------"<<endl;  
//     cout<<"\t\t-------- Game Over -------"<<endl; 

//     cout<<"\t\t--------------------------"<<endl<<endl;  
//     cout<<"\t\tPress ENTER to go back to menu.";  
//     cin.ignore();
//     cin.get(); 
// } 

void gameover() {
    system("cls");
    cout << endl;
    cout << "\t\t--------------------------" << endl;
    cout << "\t\t-------- Game Over -------" << endl;
    cout << "\t\t--------------------------" << endl << endl;
    cout << "\t\t------ FINAL SCORE: " << score << "------"<< endl;

    //cout << "\t\tPress ENTER to go back to menu.";

    // Start a timer for 5 seconds
    time_t startTime = time(nullptr);
    while (difftime(time(nullptr), startTime) < 5) {
        // Wait
    }
	modes();
    cin.ignore();
    //cin.get();
}


class gamePlay{
protected:
    void drawBorder() {
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < 17; j++) {
                gotoxy(0 + j, i);
                cout << "||";
                gotoxy(WIN_WIDTH - j, i);
                cout << "||";
        }
    }

        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            gotoxy(SCREEN_WIDTH, i);
            cout << "||";
    }
}

    void updateScore() {
        gotoxy(WIN_WIDTH + 7, 5);
        cout << "Score: " << score << endl;
}
    
     virtual void drawCar() = 0;
//         for (int i = 0; i < 4; i++) {
//             for (int j = 0; j < 4; j++) {
//                 gotoxy(j + carPos, i + 22);
//                 cout << car[i][j];
//         }
//     }
// }
    
    int collision() {
        if ((enemyY[0]) + 4 >= 23) {
            if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9) {
                return 1;
        }
    }
    return 0;
}

    void eraseCar() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                gotoxy(j + carPos, i + 22);
                cout << " ";
        }
    }
}

    virtual void play() = 0;

};


class enemyClass{
protected:
 
    virtual void drawEnemy(int ind) = 0;

    void genEnemy(int ind) {
        enemyX[ind] = 17 + rand() % (33);
}

    void eraseEnemy(int ind) {
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
 
    void resetEnemy(int ind) {
        eraseEnemy(ind);
        enemyY[ind] = 1;
        genEnemy(ind);
}
};

class easyClass : public enemyClass, public gamePlay {
    const char car[4][4] = {' ', 'O', 'O', ' ',
                            	'O', '*', '*', 'O',
                            	' ', '*', '*', ' ',
                            	'O', '*', '*', 'O'};
  public:
    void drawCar() override{
         for (int i = 0; i < 4; i++) {
             for (int j = 0; j < 4; j++) {
                gotoxy(j + carPos, i + 22);
                cout << car[i][j];            

    }
}
    }

    void drawEnemy(int ind) override{
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

    void play();
    //  void drawEnemy(int ind);
    //  void eraseEnemy(int ind);
    //  void resetEnemy(int ind);
    //  void drawBorder();		
    //  int collision();
    //  void updateScore();	  
    //  void drawCar();
    //  void eraseCar();
    //  void genEnemy(int ind);			
};

void easyClass::play() {
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
    cout << "Press ENTER to begin";
    cin.ignore(); 
    cin.get();    
    gotoxy(18, 5);
    cout << "                        ";

    while (true) {
        if (GetAsyncKeyState('A') & 0x8000) {
            if (carPos > 18)
                carPos -= 4;
        }

        if (GetAsyncKeyState('D') & 0x8000) {
            if (carPos < 50)
                carPos += 4;
        }

        if (GetAsyncKeyState('E') & 0x8000) {
            main();
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



class mediumClass : public enemyClass, public gamePlay {
  
   const char car[4][4] = {' ', 'X', 'X', ' ',
                               'X', '*', '*', 'X',
                               ' ', '*', '*', ' ',
                               'X', '*', '*', 'X'};
  
  
  public:
    void drawCar() override{
         for (int i = 0; i < 4; i++) {
             for (int j = 0; j < 4; j++) {
                gotoxy(j + carPos, i + 22);
                cout << car[i][j];            
                }
        }
    }

    void drawEnemy(int ind) override{
        if (enemyFlag[ind] == true) {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "|  |";
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "XXXX";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " XX ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "XXXX";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " vv ";
    }
}

    void play() override{
    system("color f");
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
    cout << "Press ENTER to begin";
    cin.ignore(); 
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
            main();
            return;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            exit(0);
            return;
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
        // speed of enemy
        if (enemyFlag[0] == 1)
            enemyY[0] += 2;

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

    
};


// void mediumClass::play(){
//     system("color f");
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
//     cout << "A - Left";
//     gotoxy(WIN_WIDTH + 2, 15);
//     cout << "D - Right";
//     gotoxy(WIN_WIDTH + 2, 16);
//     cout << "E - Exit";

//     gotoxy(18, 5);
//     cout << "Press ENTER to begin";
//     cin.ignore(); 
//     cin.get();    
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
//         if (GetAsyncKeyState('E') & 0x8000) {
//             // Exit
//             return;
//         }
//         if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
//             // Exit
//             return;
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
//         // speed of enemy
//         if (enemyFlag[0] == 1)
//             enemyY[0] += 2;

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



class hardClass : public enemyClass, public gamePlay {
  const char car[4][4] = {{' ', '^', '^', ' '},
                            {'[', '<', '<', ']'},
                            {' ', '<', '<', ' '},
                            {'[', '<', '<', ']'}};
  
  public:
    
    void drawCar() override{
         for (int i = 0; i < 4; i++) {
             for (int j = 0; j < 4; j++) {
                gotoxy(j + carPos, i + 22);
                cout << car[i][j];
      }
    }
}

    void drawEnemy(int ind) override{
        if (enemyFlag[ind] == true) {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "|  |";
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "OOOO";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " OO ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "OOOO";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " vv ";
    }
}

    void play();
    // void drawEnemy(int ind);
    // void eraseEnemy(int ind);
    // void resetEnemy(int ind);
    // void drawBorder();		
    // int  collision();
    // void updateScore();	  
    // void drawCar();
    // void eraseCar();
    // void genEnemy(int ind);

};

// void hardClass::play() {
//     system("color 6");
//     carPos = -1 + WIN_WIDTH / 2;
//     score = 0;
//     for (int i = 0; i < 3; ++i)
//         enemyFlag[i] = false;
//     for (int i = 0; i < 2; ++i)
//         enemyY[i] = 1;

//     drawBorder();
//     updateScore();
//     genEnemy(0);
//     genEnemy(1);
//     genEnemy(2);
//     genEnemy(3);

//     gotoxy(WIN_WIDTH + 7, 2);
//     cout << "THE CAR GAME";
//     gotoxy(WIN_WIDTH + 6, 4);
//     cout << "---------";
//     gotoxy(WIN_WIDTH + 7, 12);
//     cout << "CONTROLS:";
//     gotoxy(WIN_WIDTH + 7, 13);
//     cout << "---------";
//     gotoxy(WIN_WIDTH + 2, 14);
//     cout << "A - Left";
//     gotoxy(WIN_WIDTH + 2, 15);
//     cout << "D - Right";
//     gotoxy(WIN_WIDTH + 2, 16);
//     cout << "E - Exit";

//     gotoxy(18, 5);
//     cout << "Press ENTER to begin";
//     cin.ignore(); 
//     cin.get();   
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
//         if (GetAsyncKeyState('E') & 0x8000) {
//             exit(0);
//             return;
//         }
//         if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            
//             return;
//         }

//         drawCar();
//         for (int i = 0; i < 4; ++i)
//             drawEnemy(i);

//         if (collision() == 1) {
//             gameover();
//             return;
//         }
//         Sleep(50);
//         eraseCar();
//         for (int i = 0; i < 4; ++i)
//             eraseEnemy(i);

//         for (int i = 0; i < 4; ++i) {
//             if (enemyY[i] == 10) {
//                 if (!enemyFlag[i])
//                     enemyFlag[i] = true;
//                 enemyY[i] += 3;
//             }

//             if (enemyY[i] > SCREEN_HEIGHT - 4) {
//                 resetEnemy(i);
//                 score++;
//                 updateScore();
//             }
//         }
//     }
// }

void hardClass::play() {
	
	system("color 6");
	carPos = -1 + WIN_WIDTH/2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyY[0] = enemyY[1] = 1;
	
	system("cls");
	drawBorder();
	updateScore();
	genEnemy(0);
	genEnemy(1);
	genEnemy(2);
	genEnemy(3);
	
	gotoxy(WIN_WIDTH + 7, 2); cout << "THE CAR GAME";
	gotoxy(WIN_WIDTH + 6, 4); cout << "---------";
	gotoxy(WIN_WIDTH + 7, 12); cout << "CONTROLS:";
	gotoxy(WIN_WIDTH + 7, 13); cout << "---------";
	gotoxy(WIN_WIDTH + 2, 14); cout << "A - Left";
	gotoxy(WIN_WIDTH + 2, 15); cout << "D - Right";
	gotoxy(WIN_WIDTH + 2, 16); cout << "E - Exit";
	
	gotoxy(18, 5); cout << "Press Enter to begin";
    cin.ignore(); 
    cin.get();  
	gotoxy(18, 5); cout << "                        ";
	
	
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
            main();
            return;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            exit(0);
            return;
        }

		
		drawCar();
		drawEnemy(0);
		drawEnemy(1);
		drawEnemy(2);
		drawEnemy(3);
		
		if ( collision() == 1) {
			gameover();
			return;
		}
		Sleep(50);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);
		eraseEnemy(2);
		eraseEnemy(3);
		
		
		if (enemyY[0] == 10)
			if( enemyFlag[1] == 0 )
		    	enemyFlag[1] = 1;
		    	// speed of enemy
			if(enemyFlag[0] == 1)
				enemyY[0] += 3;
			if ( enemyFlag[1] == 1)
				enemyY[1] += 3;
			if ( enemyFlag[2] == 1)
				enemyY[2] += 3;	
			if ( enemyFlag[3] == 1)
				enemyY[3] += 3;	
			if(enemyY[0] > SCREEN_HEIGHT - 4) {
				resetEnemy(0);
				score++;
				updateScore();
			}
			if( enemyY[1] > SCREEN_HEIGHT- 4) { 
				resetEnemy(1);
				score++;
				updateScore();
			}
			if( enemyY[2] > SCREEN_HEIGHT- 4) { 
				resetEnemy(2);
				score++;
				updateScore();
			}
			if( enemyY[3] > SCREEN_HEIGHT- 4) { 
				resetEnemy(3);
				score++;
				updateScore();
			}
	}
	
}



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
        eC.play();
        break;
      case '2':
        mC.play();
        break;
      case '3':
        hc.play();
        break;
      case '4':
        //main();
        exit(0);
        break;
      default:
        cout << "Invalid! Try again";
        Sleep(888);
        break;
    }

  } while (1);



}

void instructions() {
    //setcursor(0,0);
    //srand((unsigned)time(NULL));
    system("cls");
    gotoxy(50, 5);
    cout << " ------------------- ";
    gotoxy(50, 6);
    cout << " |     CAR GAME    |";
    gotoxy(50, 7);
    cout << " ------------------- ";
    gotoxy(50, 9);
    cout << "Welcome to the Car Game!" << endl << endl;
    cout << "Instructions:" << endl;
    cout << "- Use 'A' to move your car left and 'D' to move it right." << endl;
    cout << "- Avoid crashing into other cars on the road." << endl;
    cout << "- The game speeds up as you progress." << endl << endl;
    cout << "Press E to go back to Main Menu.";
    cin.ignore();
    getchar(); 
}

int main() {
  setcursor(0,0);
  srand((unsigned)time(NULL));

  do {
    system("cls");
    system("color A");
    gotoxy(50,5); cout << " ------------------- ";
    gotoxy(50,6); cout << " |     CAR GAME    |";
    gotoxy(50,7); cout << " ------------------- ";
    gotoxy(50,9); cout << " 	PLAY      	";
    gotoxy(50,10); cout << " 	INSTRUCTIONS	";
    gotoxy(50,11); cout << " 	QUIT			";
    gotoxy(50,13); cout << ">>> CHOICE:		";
    char op = cin.get();
    cin.ignore();

    switch(op) {
      case '1':
        modes();
        break;
      case '2':
        instructions();
        break;
      case '3':
        exit(0);
        break;
      default:
        cout << "Invalid! Try again";
        break;
    }

  } while (1);
}
