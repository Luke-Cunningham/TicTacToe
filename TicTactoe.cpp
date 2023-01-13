//
// Created by Luke Cunningham on 1/13/23.
//

#include "TicTactoe.h"
#include <iostream>
using namespace std;


TicTactoe::TicTactoe() {
    for (int i = 0; i < GRID_SIZE; i++) {
        _gameGrid[i] = ' ';
    }
    _currentTurn = PLAYER_1;
}

TicTactoe::~TicTactoe() {
}

void TicTactoe::drawBoard() {
    cout << "+---+---+---+\n";
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << "| " << _gameGrid[i] << " ";
        if ((i + 1) % 3 == 0 && i != 0) {
            cout << "|\n";
            cout << "+---+---+---+\n";
        }
    }
}

int TicTactoe::getCurrentPlayer() {
    return _currentTurn;
}

bool TicTactoe::playerTakeTurn(int space) {
    // TODO: validate that this space is between 0 and GRID_SIZE - 1
    // TODO: validate that this space is not already occupied
    // if either fail, return false

    if (_currentTurn == PLAYER_1) {
        _gameGrid[space] = 'X';
        _currentTurn = PLAYER_2;
    } else {
        _gameGrid[space] = 'O';
        _currentTurn = PLAYER_1;
    }
    return true;
}

bool TicTactoe::isBoardFull() {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (_gameGrid[i] == ' ') {
            return false;
        }
    }
    return true;
}

int TicTactoe::checkWinner() {
    return _rowWon() || _columnWon() || _diagonalWon();
}

int TicTactoe::_rowWon() {
    for (int i = 0; i < GRID_SIZE; i+=3) {
        if (_gameGrid[i] != ' ' && _gameGrid[i+1] != ' ' && _gameGrid[i+2] != ' ') {
            if (_gameGrid[i] == _gameGrid[i+1] && _gameGrid[i] == _gameGrid[i+2]) {
                if (_gameGrid[i] == 'X') {
                    return PLAYER_1;
                } else {
                    return PLAYER_2;
                }
            }
        }
    }
    return 0;
}

int TicTactoe::_columnWon() {
    return 0;
}

int TicTactoe::_diagonalWon() {
    return 0;
}