//
// Created by Luke Cunningham on 1/13/23.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H


class TicTactoe {
public:
    TicTactoe();
    ~TicTactoe();

    void drawBoard();
    int getCurrentPlayer();
    bool playerTakeTurn(int space);
    bool isBoardFull();
    int checkWinner();

private:
    const static int GRID_SIZE = 9;
    const static int PLAYER_1 = 1;
    const static int PLAYER_2 = 2;
    char _gameGrid[GRID_SIZE];
    int _currentTurn;

    int _rowWon();
    int _columnWon();
    int _diagonalWon();
};

#endif //TICTACTOE_TICTACTOE_H