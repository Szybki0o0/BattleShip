#pragma once

#include <iostream>
#include <string>
#include "Board.cpp"
#include "Player.cpp"
#include "BoardShips.cpp"
#include "Ship.cpp"
#include <windows.h>

using namespace std;

void mainMenu()
{
    string value;
    cout << "To start the game enter start \nTo end programme enter end" << endl;
    cin >> value;
    if (value == "start") cout << "placeholder\n";
    else if (value == "end") exit(0);
    else cout << "Wrong syntax" << endl;
}

Ship verticalPlacement(int x, int y, int count,int firstSize,int secondSize)
{
    Ship ship(count, x, y, firstSize, secondSize);
    return ship;
}

Ship horizontalPlacement(int x, int y, int count, int firstSize, int secondSize)
{
    Ship ship(count, x, y, secondSize, firstSize);
    return ship;
}

int main()
{
    //bool isPrePhase = true;
    int count = 0, firstSize = 4, secondSize = 1;
    string exp;
    string err = "Wrong Input!!!\n\n";
    int x{}, y{};
    //mainMenu();

    BoardShips boardShip1(0);
    Board board1(0,boardShip1);

    BoardShips boardShip2(1);
    Board board2(1,boardShip2);



    //Ship ship(0, 5, 3, 1, 1);
    //boardShip1.addShipp(test);
    //boardShip1.changeFieldState(4, 5);
    //board1.changeFieldIcon(4, 5);

    Player player1("TheBill", 0);
    Player player2("Juliusz", 1);

    //vector<vector<char>> player1Board = board1.getBoard();
    //vector<vector<char>> player2Board = board2.getBoard();

    //board1.printBoard();
    //board2.printBoard();
    player1.setTurn(true);

    for (;;)
    {
        if (count < 20)
        {          
            cout << "Next ship: ";
            cin >> exp;
            if (count == 10) { firstSize = 4; }
            if (count < 10) {
                if (size(exp) == 4 && exp[1] == '1') {                
                    x = 9; y = int(exp[0]) - 97; 
                    if (exp[3] == 'v') { boardShip1.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else if (exp[3] == 'h') { boardShip1.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else { cout << err; continue; }
                }
                else if (size(exp) == 3) { 
                    y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; 
                    if (exp[2] == 'v') { boardShip1.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else if (exp[2] == 'h') { boardShip1.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else { cout << err; continue; }
                }
                else { cout << err; }
                boardShip1.showBoardShips();
            }
            else {
                if (size(exp) == 4 && exp[1] == '1') {
                    x = 9; y = int(exp[0]) - 97;
                    if (exp[3] == 'v') { boardShip2.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else if (exp[3] == 'h') { boardShip2.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else { cout << err; continue; }
                }
                else if (size(exp) == 3) {
                    y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1;
                    if (exp[2] == 'v') { boardShip2.addShip(verticalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else if (exp[2] == 'h') { boardShip2.addShip(horizontalPlacement(x, y, count, firstSize, secondSize)); count++; }
                    else { cout << err; continue; }
                }
                else { cout << err; }
                boardShip2.showBoardShips();
            }
            if (count == 1 || count == 3 || count == 6 || count == 11 || count == 13 || count == 16) { firstSize -= 1; }
        }
        else
        {
            /*if (player1.getTurn())
            {
                boardShip1.showBoardShips();
                board1.printBoard();
                player1.setTurn(false);
                player2.setTurn(true);
                cout << player1.getName() << " guess: ";
                cin >> exp; cout << "\n";
                if (size(exp) == 3 && exp[1] == '1') { x = 9; y = int(exp[0]) - 97; }
                else if (size(exp) == 2) { y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; }
                else { cout << "Wrong Input!!!\n\n"; player2.setTurn(false); player1.setTurn(true); }

            }

            if (player2.getTurn())
            {
                boardShip2.showBoardShips();
                board2.printBoard();
                player1.setTurn(true);
                player2.setTurn(false);
                cout << player2.getName() << " guess: ";
                cin >> exp; cout << "\n";
                if (size(exp) == 3 && exp[1] == '1') { x = 9; y = int(exp[0]) - 97; }
                else if (size(exp) == 2) { y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; }
                else { cout << "Wrong Input!!!\n\n"; player1.setTurn(false); player2.setTurn(true); }
            }*/

        }

        
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            //cout << "ESCAPE-PRESSED" << endl;
            //mainMenu();
            Sleep(500);
        }
    }
}
