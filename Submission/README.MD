# OOP PROJECT FINAL REPORT
## SURVIVING CAR GAME
### Creators:
| Name             | ID       |
|------------------|----------|
| Rayyan Merchant | 23K-0073 |
| Riya Bhart       | 23K-0063 |
| Syeda Rija Ali   | 23K-0057 |


#### Instructor: Talha Shahid
#### Section: BSAI-2A

## Introduction
The Car Game project is a console-based game developed in C++ that simulates a car driving experience. Players control a car moving along a road while avoiding collisions with other cars. The game offers three difficulty modes: Easy, Medium, and Hard, each with different speeds and challenges.

## Objective
The objective of the game is to achieve the highest score possible by maneuvering the player's car safely through traffic without crashing into other vehicles. As the game progresses, the speed of the player's car and the frequency of other cars increase, making it more challenging to avoid collisions.

## Features
1. **Multiple Difficulty Modes:** The game offers three difficulty modes - Easy, Medium, and Hard, providing players with different levels of challenge and speed.
2. **Real-time Gameplay:** The game provides real-time gameplay where players can control their car using the keyboard inputs.
3. **Score Tracking:** The game keeps track of the player's score, which increases as the player successfully avoids collisions and progresses through the game.
4. **Collision Detection:** The game detects collisions between the player's car and other cars on the road, triggering a game over screen when a collision occurs.
5. **Instructions:** The game includes an instruction screen that explains the controls and gameplay mechanics to the player.

## Implementation

### Libraries Used
- **iostream:** Standard input-output stream library for console input and output operations.
- **windows.h:** Windows API library used for console manipulation, including functions like `GetStdHandle()` for retrieving standard output handle, `SetConsoleCursorPosition()` for setting cursor position, and `SetConsoleCursorInfo()` for cursor visibility.
- **time.h:** Standard time library for time-related functions, used for implementing delays and timing game events.
- **cstdlib:** Standard C library for general-purpose functions, used for functions like `exit()` for program termination.

### Algorithm and Logic
1. **Console Cursor Manipulation:** The `gotoxy()` function is used to position the cursor on the console screen, allowing for precise output positioning.
2. **Input Handling:** The `GetAsyncKeyState()` function is used to detect keyboard inputs in real-time.
3. **Gameplay Logic:** Each difficulty mode is implemented as a separate class (`easyClass`, `mediumClass`, `hardClass`) inheriting from base classes for gameplay and enemy car behavior.
4. **Randomization:** The `srand()` function from the `cstdlib` library is used to seed the random number generator.

### Project Structure
- **Main File:** Contains the main function for starting the game and implementing the main menu functionality.
- **Gameplay Classes:** Includes classes for different difficulty modes (`easyClass`, `mediumClass`, `hardClass`) implementing gameplay mechanics and enemy car behavior.
- **Utility Functions:** Contains utility functions like `gotoxy()` for cursor positioning and `setcursor()` for cursor visibility.
- **Header Files:** May include header files for class declarations and function prototypes.

## Challenges
1. **Real-time Input Handling:** Implementing real-time input handling for smooth gameplay required handling asynchronous keyboard inputs using the `GetAsyncKeyState()` function.
2. **Collision Detection:** Accurately detecting collisions between the player's car and enemy cars involved precise positioning and collision detection algorithms.
3. **Game Speed Scaling:** Adjusting the speed of the player's car and enemy cars dynamically as the game progresses presented a challenge.
4. **Testing:** Thorough testing was necessary to ensure the game behaved as expected under various conditions.
5. **Designing the Interface:** Designing a user-friendly interface that provided clear instructions, controls, and feedback to the player while maintaining a visually appealing layout was a challenge.
6. **Enemy and Player Car Design:** Designing visually distinct enemy and player cars using characters within the console environment presented challenges in balancing readability, aesthetics, and gameplay clarity.

## OOP Concepts
1. **Inheritance:** The project utilizes inheritance to implement different difficulty modes, inheriting from base classes for gameplay and enemy car behavior.
2. **Polymorphism:** Polymorphism is demonstrated through function overriding in derived classes to provide custom implementations of virtual functions defined in base classes.
3. **Encapsulation:** Encapsulation is achieved by encapsulating related functionality within classes and providing access control through public and protected member functions and variables.
4. **Abstraction:** Abstraction is utilized to hide implementation details and provide a simplified interface for interacting with game objects and mechanics.
5. **Modularity:** The project demonstrates modularity by organizing code into separate classes for different gameplay components and difficulty modes.


### Members' Contribution:

1. Rayyan Merchant (23K-0073):
   - Implemented the gameplay logic for the medium difficulty mode.
   - Worked on collision detection and scoring mechanisms.
   - Handled the console manipulation and cursor positioning.
   - Assisted in testing and debugging.

2. Riya Bhart (23K-0063):
   - Implemented the gameplay logic for the easy difficulty mode.
   - Designed the user interface including the instruction screen.
   - Handled the integration of input handling functions.
   - Assisted in testing and documentation.

3. Syeda Rija Ali (23K-0057):
   - Implemented the gameplay logic for the hard difficulty mode.
   - Designed and implemented the main menu functionality.
   - Handled the integration of enemy and player car designs.
   - Assisted in testing and refining the game mechanics.



## Conclusion
The Car Game project demonstrates the application of C++ programming concepts in game development, utilizing libraries like `windows.h` and `time.h` for console manipulation and timing functions. By implementing various gameplay mechanics and difficulty modes, the project provides an engaging and challenging gaming experience for players. With its modular design and clear separation of concerns, the project showcases good programming practices and lays the foundation for further enhancements and feature additions.



## Video Demo: 
https://drive.google.com/file/d/1bzLyIb_ExK8noNYGTswOGH10pGxUsvm3/view?t=107
