#include <iostream>
#include <string>
#include "Board.cpp"
#include "Player.cpp"
#include "ShipTypes.cpp"
#include <windows.h>

using namespace std;

void mainMenu()
{
    string value,p1name,p2name;
    cout << "To start the game enter start \nTo end programme enter end" << endl;
    cin >> value;
    cout << "Enter Player 1 name: ";
    cin >> p1name;
    cout << "Enter Player 2 name: ";
    cin >> p2name;

    if (value == "start") cout << "placeholder\n";
    else if (value == "end") exit(0);
    else cout << "Wrong syntax" << endl;
}

int main()
{
    //mainMenu();

    Board board1(0);
    Board board2(1);

    Player player1("Bill", 0);
    Player player2("Juliusz", 1);

    ShipTypes ones("one", 1, 0);
    ShipTypes twos("two", 2, 1);
    ShipTypes threes("one", 3, 2);
    ShipTypes fours("one", 4, 3);


    board1.createBoard(board1.getBoard());
    board1.createSecBoard(board1.getSecBoard());

    board2.createBoard(board2.getBoard());
    board2.createSecBoard(board2.getSecBoard());

    player1.setTurn(true);

    //ones.ones(1, 2, board1.getSecBoard());
    //board1.printBoard(ones.ones("c4", board1.getSecBoard()));
    board1.printBoard(twos.twos("c4c3", board1.getSecBoard()));
 
    for (;;)
    {
        //if (board1.isEnd(board1.getSecBoard()) == true) cout << player1.getName() << " has won!"; break;
        //if (board2.isEnd(board2.getSecBoard()) == true) cout << player2.getName() << " has won!"; break;

        if (player1.getTurn())
        {
            //board1.printBoard(board1.getBoard());
            string exp;
            int x{}, y{};
            cout << player1.getName() << " guess: ";
            cin >> exp;
            if (int(exp[0]) < 107 && int(exp[0]) > 95 && int(exp[1] - '0') >= 0 && int(exp[1] - '0') < 10)
            {
                if (size(exp) == 3) { x = 9; y = int(exp[0]) - 97; }
                else { y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; }
                board1.changeMatrix(x, y, board1.getBoard(), board1.getSecBoard());
                player1.setTurn(false);
                player2.setTurn(true);
            }
            else cout << "Wrong input!!!\n";
        }

        if (player2.getTurn())
        {
            //board2.printBoard(board2.getBoard());
            string exp;
            int x{}, y{};
            cout << player2.getName() << " guess: ";
            cin >> exp;
            if (int(exp[0]) < 107 && int(exp[0]) > 95 && int(exp[1] - '0') >= 0 && int(exp[1] - '0') < 10)
            {
                if (size(exp) == 3) { x = 9; y = int(exp[0]) - 97; }
                else { y = int(exp[0]) - 97; x = int(exp[1] - '0') - 1; }
                board2.changeMatrix(x, y, board2.getBoard(), board2.getSecBoard());
                player1.setTurn(true);
                player2.setTurn(false);
            }
        }
    
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            //mainMenu();
            Sleep(500);
        }
    }
}
