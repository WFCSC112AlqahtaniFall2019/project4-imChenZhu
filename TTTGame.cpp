/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    TicTacToe game;
    int currentPlayerNumber;
    int row;
    int column;

    cout << "One-player or Two-player (1 or 2):";
    cin >> currentPlayerNumber;
    game.initializeBoard();
    game.printBoard();

    while (1) {
        if (currentPlayerNumber == 1) {
            cout << "Player :" << endl;
            cout << "Enter row and column: ";
            cin >> row >> column;
            bool currPosition = game.placeMark(row - 1, column - 1);

            while (currPosition != true)
            {
                cout << "This position is taken, please choose another one: " << endl;
                cin >> row >> column;
                currPosition = game.placeMark(row-1, column-1);
            }
            game.printBoard();
            game.changePlayer();
            if (game.checkForWin()) {
                cout << "Player 1 wins" << endl;
                break;
            }

            if(game.isBoardFull()){
                cout<<"Draw"<<endl;
                cout<<"Try another round"<<endl;
                return 0;
            }


            srand(int(time(0)));
            row = rand() % 3 + 1;
            column = rand() % 3 + 1;
            cout << "Player 2:" << endl;
            cout << "Enter row and column: "<<row<<" "<<column;
            currPosition = game.placeMark(row - 1, column - 1);

            while (currPosition != true) {
                cout << "This position is taken, please choose another one: " << endl;
                srand(int(time(0)));
                row = rand() % 3 + 1;
                column = rand() % 3 + 1;
                currPosition = game.placeMark(row - 1, column - 1);
            }
            game.printBoard();
            game.changePlayer();
            if (game.checkForWin()) {
                cout << "Player 2 wins" << endl;
                break;
            }

        }


        else if (currentPlayerNumber == 2) {
            cout << "Player 1:" << endl;
            cout << "Enter row and column: ";
            cin >> row >> column;
            bool currPosition = game.placeMark(row - 1, column - 1);

            while (currPosition != true) {
                cout << "This position is taken, please choose another one: " << endl;
                cin >> row >> column;
                currPosition = game.placeMark(row - 1, column - 1);
            }
            game.printBoard();
            game.changePlayer();
            if (game.checkForWin()) {
                cout << "Player 1 wins" << endl;
                break;
            }

            if (game.isBoardFull()) {
                cout << "Draw" << endl;
                cout << "Try another round" << endl;
                return 0;
            }


                cout << "Player 2:" << endl;
                cout << "Enter row and column: ";
                cin >> row >> column;
                currPosition = game.placeMark(row - 1, column - 1);

                while (currPosition != true) {
                    cout << "This position is taken, please choose another one: " << endl;
                    cin >> row >> column;
                    currPosition = game.placeMark(row - 1, column - 1);
                }
                game.printBoard();
                game.changePlayer();
                if (game.checkForWin()) {
                    cout << "Player 2 wins" << endl;
                    break;
                }

                if (game.isBoardFull()) {
                    cout << "Draw" << endl;
                    cout << "Try another round" << endl;
                }
            }

    }

    return 0;
}