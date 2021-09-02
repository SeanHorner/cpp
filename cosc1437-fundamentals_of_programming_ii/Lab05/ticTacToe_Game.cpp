#include <iostream>
#include "ticTacToe.h"

int main() {
	 int selectPlayers;
	 int row;
	 int col;
	 bool movePlaced = false;
	 ticTacToe square;
	 
	 do {
		cout << "********************************\n"
			 << " 1: Single Player (vs. Computer)\n"
			 << " 2: Two Players\n"
			 << "********************************\n";
		cin >> selectPlayers;
		cout << endl;
	 
		if (selectPlayers < 1 || selectPlayers > 2) {
			cout << "Unacceptable answer, please try again. ";
			cin >> selectPlayers;
			cout << endl;
		}
	} while (selectPlayers < 1 || selectPlayers > 2);
	
	switch (selectPlayers) {
		case 1:
			do {
				do {
					movePlaced = false;
					
					cout << "Enter row number:    ";
					cin >> row;
					cout << endl;
				
					cout << "Enter column number: ";
					cin >> col;
					cout << endl;
				
					if (square.checkMove(row-1, col-1)) {
						square.placeMove(1, row-1, col-1);
						movePlaced = true;
					} else
						cout << "That space is already taken. Try again.";
				} while (movePlaced == false);
				
				square.showBoard();
				
				if (square.isWinner()) {
					cout << "PLAYER is the winner!";
					break;
				}
				
				do {
					movePlaced = false;
					
					row = rand() % 3;
					col = rand() % 3;
					
					if (square.checkMove(row, col)) {
						square.placeMove(2, row, col);
						movePlaced = true;
					}
				} while (movePlaced == false);
				
				square.showBoard();
				
				if (square.isWinner()) {
					cout << "Random Chance is the victor!";
					break;
				}
				
			} while (!square.isWinner());
			break;
			
		case 2:
			do {
				do {
					movePlaced = false;
					
					cout << "PLAYER 1: Enter row number:    ";
					cin >> row;
					cout << endl;
				
					cout << "PLAYER 1: Enter column number: ";
					cin >> col;
					cout << endl;
				
					if (square.checkMove(row-1, col-1)) {
						square.placeMove(1, row-1, col-1);
						movePlaced = true;
					} else
						cout << "That space is already taken. Try again.";
				} while (movePlaced == false);
				
				square.showBoard();
				
				if (square.isWinner()) {
					cout << "PLAYER 1 is the winner!";
					break;
				}
				
				do {
					movePlaced = false;
					
					cout << "PLAYER 2: Enter row number:    ";
					cin >> row;
					cout << endl;
				
					cout << "PLAYER 2: Enter column number: ";
					cin >> col;
					cout << endl;
				
					if (square.checkMove(row-1, col-1)) {
						square.placeMove(2, row-1, col-1);
						movePlaced = true;
					} else
						cout << "That space is already taken. Try again.";
				} while (movePlaced == false);
				
				square.showBoard();
				
				if (square.isWinner()) {
					cout << "PLAYER 2 is the winner!";
					break;
				}
				
			} while (!square.isWinner());
			break;
	}
	
	return 0;
}
