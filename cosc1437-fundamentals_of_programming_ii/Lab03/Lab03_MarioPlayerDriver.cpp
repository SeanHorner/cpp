#include "Lab03_MarioPlayerClass.h"
#include <iostream>
#include <string>

using namespace std;

playerType mario;	

void showMenu();
void clearScreen();

int main()
{
	mario.setName("Mario");
	
	int menuSelection;
	
	do {
	
	showMenu();
	cin >> menuSelection;
	cout << endl;
	clearScreen();
	
	int newLevel = 0;
	int new_X = 0;
	int new_Y = 0;
	int input;
	
	switch(menuSelection) {
	
	case 1:
		cout << "Enter new level number: ";
		cin >> newLevel;
		cout << endl;
		
		cout << "Enter new x position: ";
		cin >> new_X;
		cout << endl;
			
		cout << "Enter new y position: ";
		cin >> new_Y;
		cout << endl;
		
		mario.updateLevel(newLevel);
		mario.updatePos_x(new_X);
		mario.updatePos_y(new_Y);
			
		mario.printStatus();
		break;
	
	case 2:
		mario.updateCoins(95);
		cout << "\t\tCoins are now loaded.\n\n\n";
			
		do {
			mario.printStatus();			
			
			cout << "**************************\n"
				 << " 1: Add a Coin\n"
				 << " 0: Exit\n"
				 << "**************************\n\n";
			cin >> input;
			cout << "\n" << endl;
				
			if (input == 1) {
				mario.getCoin();
			} else if (input == 0) {
				clearScreen();
				cout << "\tEnding test...\n\n\n\n";
			} else
				cout << "Inappropriate entry, please enter 0 or 1.\n\n";
				
		} while (input != 0);
			
		break;
	
	case 3:
		do {
			mario.printStatus();			
			
			cout << "**************************\n"
				 << " 1: Continue Combo\n"
				 << " 0: Exit\n"
				 << "**************************\n\n";
			cin >> input;
			cout << endl;
		
			if (input == 1)
				mario.combo();
			else if (input == 0) {
				cout << "\tNow exiting...\n\n\n\n\n";
				mario.endCombo();
			}
			else
				cout << "Inappropriate entry, please enter 0 or 1.\n\n";
		
		} while (input != 0);
		
		break;
	
	case 4:	
		do {
			mario.printStatus();			
			
			cout << "**************************\n"
				 << " 1: 1-Up Mushroom\n"
				 << " 2: Super Mushroom\n"
				 << " 0: Exit\n"
				 << "**************************\n\n";
			cin >> input;
			cout << endl;
			
			if (input == 1) {
				mario.lifeUp();
				cout << "Life up!\n\n";
			} else if (input == 2) {
				if (mario.isLarge()) {
					cout << "Mario is already big!\n\n";
				} else {
					mario.bigMushroom();
				}
			} else if (input == 0) {
				clearScreen();
				cout << "\tNow exiting...\n";
				break;
			} else {
				cout << "Inappropriate entry, please enter 0, 1, or 2.\n\n";
			}
		
		} while (input != 0);
		
		break;
	
	case 5:
		do {
			mario.printStatus();
			
			cout << "**************************\n"
				 << " 1: Sustain Damage\n"
				 << " 0: Exit\n"
				 << "**************************\n\n";
			cin >> input;
			cout << endl;
			
			if (input == 1) {
				mario.getHit();
			} else if (input == 0) {
				cout << "\tNow exiting...\n\n\n";
			}
		
		} while (input != 0);
		
		break;
	
	case 6:
		do {
			mario.printStatus();
			
			cout << "**************************\n"
				 << " 1: Move Forward\n"
				 << " 2: Move Backward\n"
				 << " 0: Exit\n"
				 << "**************************\n\n";
			cin >> input;
			cout << endl;
			
			if (input == 1)
				mario.forward();
			else if (input == 2)
				mario.backward();
			else if (input == 0)
				cout << "\n\n\n\tNow exiting...\n\n\n";
			
		} while (input != 0);
		
		break;
		
	case 7:
		do {
			mario. printStatus();
			
			cout << "**************************\n"
				 << " 1: Fire Flower\n"
				 << " 2: Invincibility Star\n"
				 << " 0: Exit\n"
				 << "**************************\n\n";
			cin >> input;
			cout << endl;
			
			switch(input) {
				case 1:
					mario.fireFlower();
					break;
				case 2:
					mario.invincibleStar();
					break;
				case 0:
					cout << "\tNow exiting...\n\n\n";
					break;
					
			}
		
		} while (input != 0);
		
		break;
	
	case 0:
		cout << "\tNow exiting...\n\n\n";

		break;
	}
	
	} while (menuSelection != 0);
	
	return 0;
}

void showMenu() {
	cout << "**********************************\n"
		 << " 1: Update Position\n"
		 << " 2: Coin Test\n"
		 << " 3: Combo Test\n"
		 << " 4: Mushroom Test\n"
		 << " 5: Damage Test\n"
		 << " 6: Movement Test\n"
		 << " 7: Special Item Test\n"
		 << " 0: Exit Program\n"
		 << "**********************************\n\n";
		 
	return;
}

void clearScreen() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;;

	return;
}
