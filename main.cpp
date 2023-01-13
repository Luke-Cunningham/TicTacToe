#include "TicTactoe.h"
#include <iostream>
using namespace std;


int main() {
    TicTactoe game;

    cout << "Tic Tac Toe!\n";
    game.drawBoard();

    while (!game.isBoardFull()) {
        int player = game.getCurrentPlayer();
        cout << "Player " << player << " turn ... select a space 0-8: ";
        int space;
        cin >> space;
        // TODO - add user entry validation

        while (!game.playerTakeTurn(space)) {
            cout << "Space occupied or is invalid please select another space\n";
            cin >> space;
        }
        game.drawBoard();
        int winner = game.checkWinner();
        if (winner != 0) {
            cout << "Player " << winner << " wins!\n";
            break;
        }
    }
    if (!game.checkWinner()) {
        cout << "It was a draw!\n";
    }
    return 0;
}
