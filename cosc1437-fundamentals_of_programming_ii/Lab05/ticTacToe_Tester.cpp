#include <iostream>
#include "ticTacToe.h"

using namespace std;

int main() {
	ticTacToe game;
	
	game.placeMove(1, 0, 0);
	game.showBoard();
	
	if (game.isWinner()) {
		cout << "A winner!\n";
	}
	
	game.placeMove(1, 0, 1);
	game.showBoard();
	
	if (game.isWinner()) {
		cout << "A winner!\n";
	}
	
	game.placeMove(1, 0, 2);
	game.showBoard();

	if (game.isWinner()) {
		cout << "A winner!\n";
	}

	return 0;
}
