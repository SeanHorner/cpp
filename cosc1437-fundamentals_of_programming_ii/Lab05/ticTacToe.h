#ifndef ticTacToe_H
#define ticTacToe_H

#include <iostream>

using namespace std;

class ticTacToe {
	private:
		char board[3][3];
		
	public:
		ticTacToe() {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					board[i][j] = 'a';
			}
		}
		
		bool checkMove(int i, int j) {
			if (board[i][j] == 'a')
				return true;
			
			return false;
		}
		
		void placeMove(int playerNum, int i, int j) {
			char userCharacter;
			
			if (playerNum == 1)
				userCharacter = 'O';
			else
				userCharacter = 'X';
			
			board[i][j] = userCharacter;
		}	
		
		void showBoard() {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (j < 2)
						cout << " " << board[i][j] << " |";
					else
						cout << " " << board[i][j] << "\n";
				}
				if (i < 2)
					cout << "-----------\n";
			}
			cout << "\n" << endl;
		}
		
		bool isWinner() {
			if ((board[0][0] != 'a') && 
				(board[0][0] == board[0][1]) && 
				(board[0][1] == board[0][2])) {
					cout << "Row 1 win!\n";
					return true;
			}
			
			if ((board[1][0] != 'a') && 
				(board[1][0] == board[1][1]) && 
				(board[1][1] == board[1][2])) {
					cout << "Row 2 win!\n";
					return true;
			}
				
			if ((board[2][0] != 'a') && 
				(board[2][0] == board[2][1]) && 
				(board[2][1] == board[2][2])) {
					cout << "Row 3 win!\n";
					return true;
			}
			
			if ((board[0][0] != 'a') && 
				(board[0][0] == board[1][0]) && 
				(board[1][0] == board[2][0])) {
					cout << "Column 1 win!\n";
					return true;
			}
				
			if ((board[0][1] != 'a') && 
				(board[0][1] == board[1][1]) && 
				(board[1][1] == board[2][1])) {
					cout << "Column 2 win!\n";
					return true;
			}
				
			if ((board[0][2] != 'a') && 
				(board[0][2] == board[1][2]) && 
				(board[1][2] == board[2][2])) {
					cout << "Column 3 win!\n";
					return true;
			}
				
			if ((board[0][0] != 'a') && 
				(board[0][0] == board[1][1]) && 
				(board[1][1] == board[2][2])) {
					cout << "Diagonal 1 win!\n";
					return true;
			}
				
			if ((board[0][2] != 'a') && 
				(board[0][2] == board[1][1]) && 
				(board[1][1] == board[2][0])) {
					cout << "Diagonal 2 win!\n";
					return true;
			}
			
			return false;
		}
	};

#endif
