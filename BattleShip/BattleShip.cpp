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

void showShipps() {

}

int main()
{
    cout.flush();
    //mainMenu();

    Board board1(0);
    Board board2(1);

    BoardShips boardShip(0);

    Ship test(0, 4, 4, 1, 1);

    boardShip.addShipp(test);
    boardShip.showBoardShips();

    Player player1("TheBill", 0);
    Player player2("Juliusz", 1);

    vector<vector<char>> player1Board = board1.getBoard();
    vector<vector<char>> player2Board = board2.getBoard();

    board1.printBoard(player1Board);
    board2.printBoard(player2Board);

    for (;;)
    {
        string exp;
        int x{}, y{};
        cout << "Next guess: ";
        cin >> exp;
        x = int(exp[0]) - 97;
        y = exp[1] - 1;

        
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            //cout << "ESCAPE-PRESSED" << endl;
            //mainMenu();
            Sleep(500);
        }
    }
}
