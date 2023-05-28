#pragma once // preventing from multiple inclusion of the source code while compiling

#include <iostream>
#include <string>
#include "Board.cpp"
#include "Player.cpp"
#include "BoardShips.cpp"
#include "Ship.cpp"
#include <windows.h>

using namespace std;

void mainMenu() // information panel
{
    cout << "To start the game press space \nTo end programme press esc" << endl;
}

Ship verticalPlacement(int x, int y, int count,int firstSize,int secondSize) // creating Ship class object more conviniently
{
    Ship ship(count, x, y, firstSize, secondSize);
    return ship;
}

Ship horizontalPlacement(int x, int y, int count, int firstSize, int secondSize) // creating Ship class object more conviniently
{
    Ship ship(count, x, y, secondSize, firstSize);
    return ship;
}

int main()
{
    // used variables in main loop
    mainMenu();
    bool isStart = false;
    int count = 0, firstSize = 4, secondSize = 1;
    string exp;
    string err = "Wrong Input!!!\n\n";
    string ofr = "Input out of range!!!\n\n";
    int x{}, y{};

    // creation of two board for two players
    BoardShips boardShip1(0);
    Board board1(0, boardShip1);

    BoardShips boardShip2(1);
    Board board2(1, boardShip2);

    // Creation of two players
    Player player1("TheBill", 0);
    Player player2("Juliusz", 1);
    
    // seting first turn for player1
    player1.setTurn(true);

    // main loop of the program
    for (;;)
    {
        if (isStart) // checking if user went out of the main menu
        {
            if (count == 10) { firstSize = 4; board2.setBoardShip(boardShip1); } // updating logic board to Board class
            if (count == 20) { board1.setBoardShip(boardShip2); }
            if (count < 20) // checking if the preparation phase has ended
            {
                cout << "Next ship: "; // taking expresion from players
                cin >> exp;
                if (count < 10) { // filling board for player1
                    if (size(exp) == 4 && exp[2] == '0' && exp[1] == '1') { // longer expresion condition if number is 10
                        x = 9; y = int(exp[0]) - 97; // prep x y cords
                        if (exp[3] == 'v' && x + firstSize <= 10) { boardShip1.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed vertically and correctly
                        else if (exp[3] == 'h' && y + firstSize <= 10) { boardShip1.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed horizontally and correctly
                        else { cout << err; continue; } // exeption handling
                    }
                    else if (size(exp) == 3) { // shorter expresion  if number is one digit
                        y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; // prep x y cords
                        if (exp[2] == 'v' && x + firstSize <= 10 && y < 10 && x < 10 && y >= 0 && x >= 0) { boardShip1.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed vertically and correctly
                        else if (exp[2] == 'h' && y + firstSize <= 10 && y < 10 && x < 10 && y >= 0 && x >= 0) { boardShip1.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed horizontally and correctly
                        else { cout << err; continue; } // exeption handling
                    }
                    else { cout << err; continue; } // exeption handling
                    boardShip1.showBoardShips(); // printing current board state
                }
                else { // filling board for player2
                    if (size(exp) == 4 && exp[2] == '0' && exp[1] == '1') { // longer expresion condition if number is 10
                        x = 9; y = int(exp[0]) - 97; // prep x y cords
                        if (exp[3] == 'v' && x + firstSize <= 10) { boardShip2.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed vertically and correctly
                        else if (exp[3] == 'h' && y + firstSize <= 10) { boardShip2.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed horizontally and correctly
                        else { cout << err; continue; } // exeption handling
                    }
                    else if (size(exp) == 3) { // shorter expresion  if number is one digit
                        y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; // prep x y cords
                        if (exp[2] == 'v' && x + firstSize <= 10 && y < 10 && x < 10 && y >= 0 && x >= 0) { boardShip2.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed vertically and correctly
                        else if (exp[2] == 'h' && y + firstSize <= 10 && y < 10 && x < 10 && y >= 0 && x >= 0) { boardShip2.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; } // checking if ship is placed horizontally and correctly
                        else { cout << err; continue; } // exeption handling
                    }
                    else { cout << err; continue; } // exeption handling
                    boardShip2.showBoardShips(); // printing current board state
                }
                if (count == 1 || count == 3 || count == 6 || count == 11 || count == 13 || count == 16) { firstSize -= 1; } // updating ship size
            }
            else
            {
                // cheking if someone has won
                if (boardShip1.isEnd()) { cout << player2.getName() << " has won!"; break; }
                if (boardShip2.isEnd()) { cout << player1.getName() << " has won!"; break; }

                // gameplay module and turn system
                if (player1.getTurn())
                {
                    board1.printBoard(); // printing current board state
                    player1.setTurn(false); // changing turn
                    player2.setTurn(true);
                    cout << player1.getName() << " guess: "; // taking expresion from player
                    cin >> exp; cout << "\n";
                    if (size(exp) == 3 && exp[1] == '1') { x = 9; y = int(exp[0]) - 97; } // longer expresion condition if number is 10
                    else if (size(exp) == 2) { y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; } // shorter expresion  if number is one digit
                    else { cout << err; player1.setTurn(true); player2.setTurn(false); continue; } // exeption handling
                    if (boardShip2.isShipOnField(x, y)) { player1.setTurn(true); player2.setTurn(false); } // cheching if hit
                    board1.changeFieldIcon(x, y); // updating game board
                    boardShip2.changeFieldState(x, y); // updating logic board
                }

                if (player2.getTurn())
                {
                    board2.printBoard(); // printing current board state
                    player1.setTurn(true); // changing turn
                    player2.setTurn(false);
                    cout << player2.getName() << " guess: "; // taking expresion from players
                    cin >> exp; cout << "\n";
                    if (size(exp) == 3 && exp[1] == '1') { x = 9; y = int(exp[0]) - 97; } // longer expresion condition if number is 10
                    else if (size(exp) == 2) { y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; } // shorter expresion  if number is one digit
                    else { cout << err; player1.setTurn(false); player2.setTurn(true); continue; } // exeption handling
                    if (boardShip1.isShipOnField(x, y)) { player1.setTurn(false); player2.setTurn(true); } // cheching if hit
                    board2.changeFieldIcon(x, y); // updating game board
                    boardShip1.changeFieldState(x, y); // updating logic board
                }

            }
        }

        if (GetAsyncKeyState(VK_ESCAPE)) // cheking if esc has been pressed
        {
            exit(0);
            Sleep(500);
        }

        if (GetAsyncKeyState(VK_SPACE)) // cheking if space has been pressed
        {
            isStart = true;
            Sleep(500);
        }
    }

}