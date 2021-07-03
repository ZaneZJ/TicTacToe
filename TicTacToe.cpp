#include <iostream>
#include <sstream>
#include <map>
#include "LinkedList.h"
using namespace std;

bool endOfTheGame(map<int,LinkedList<char>> _board, char symbol) {
    //check rows
    for ( int col = 1; col <= 3; col++) {
        if ( _board[col].at(0)->data == symbol && _board[col].at(1)->data == symbol && _board[col].at(2)->data == symbol) {
            cout << symbol << " won in the row" << endl;
            return true;
        }
    }

    //check columns
    for ( int row = 0; row < 3; row++) {
        if ( _board[1].at(row)->data == symbol && _board[2].at(row)->data == symbol && _board[3].at(row)->data == symbol) {
            cout << symbol << " won in the column" << endl;
            return true;
        }
    }

    //check diagonal
    if ( _board[1].at(0)->data == symbol && _board[2].at(1)->data == symbol && _board[3].at(2)->data == symbol) {
        cout << symbol << " won in the diagonal" << endl;
        return true;
    }

    //check anti-diagonal
    if ( _board[1].at(2)->data == symbol && _board[2].at(1)->data == symbol && _board[3].at(0)->data == symbol) {
        cout << symbol << " won in the anti-diagonal" << endl;
        return true;
    }

    return false;
}

int main() {
    map<int,LinkedList<char>> board;

    board.insert(pair<int,LinkedList<char>>(1,*(new LinkedList<char>())));
    board[1].insert(' ');
    board[1].insert(' ');
    board[1].insert(' ');
    board.insert(pair<int,LinkedList<char>>(2,*(new LinkedList<char>())));
    board[2].insert(' ');
    board[2].insert(' ');
    board[2].insert(' ');
    board.insert(pair<int,LinkedList<char>>(3,*(new LinkedList<char>())));
    board[3].insert(' ');
    board[3].insert(' ');
    board[3].insert(' ');

    bool isPlayerX = true;

    while(!endOfTheGame(board, 'X') && !endOfTheGame(board, 'O')) {
        if(isPlayerX) {
            cout << "Player X" << endl << endl;
        } else {
            cout << "Player O" << endl << endl;
        }
        int col;
        int row;
        bool validCol = false;
        bool validRow = false;
        bool isEmpty = false;
        while(!isEmpty) {
            while(!validCol) {
                cout << "Insert col number: ";
                cin >> col;
                if (col == 1 || col == 2 || col == 3) {
                    validCol = true;
                } else {
                    cout << "Invalid input! Try again!" << endl;
                }
            }
            while(!validRow) {
                cout << endl << "Insert row number: ";
                cin >> row;
                cout << endl;
                if (row == 1 || row == 2 || row == 3) {
                    row = row -1;
                    validRow = true;
                } else {
                    cout << "Invalid input! Try again!" << endl;
                }
            }

            if(board[col].at(row)->data == ' ') {
                if (isPlayerX) {
                    board[col].at(row)->data = 'X';
                } else {
                    board[col].at(row)->data = 'O';
                }

                board[1].print(col);
                board[2].print(col);
                board[3].print(col);

            } else {
                cout << "Invalid input! Try again!" << endl;
            }

        }
    }

    // board[1].clear;
    // board[2].clear;
    // board[3].clear;

}