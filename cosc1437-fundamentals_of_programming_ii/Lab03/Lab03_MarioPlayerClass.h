#ifndef playerType_H
#define playerType_H

#include <iostream>
#include <string>

using namespace std;

class playerType
{
	private:
		string name;
		int level;
		int pos_x;
		int pos_y;
		int coins = 0;
		int lives = 3;
		int comboNum = 0;
		long score = 0;
		bool isBig = false;
		bool isFire = false;
		bool isStarry = false;
		
		
	public:
		void lifeUp() {lives++;}
	
		void bigMushroom() {
			if (isBig == false)
				isBig = true;
			else 
				score += 1600;
		}
	
		void getHit() {
			if (isFire == true)
				isFire = false;
			
			if (isBig == false) {
				if (lives > 1) {
					cout << "Lost a life! Only " << lives << " left!\n\n";
					lives--;
				} else {
					cout << "Game Over!\n\n\n";
				}
			} else
				isBig = false;
		}
	
		void getCoin() {
			if (coins < 99) {
				coins++;
				cout << "You have " << coins << " coins!\n\n\n";
			} else { 
				cout << "Extra life!\n";
				lifeUp();
				coins = 0;
			}
		}
		
		void combo() {
			int points = 100;
			
			if (comboNum < 8) {
				cout << points << " points!" << endl;
				score += points;
				comboNum++;
			} else {
				cout << "Extra life!\n";
				lifeUp();
			}
			
			points = 2 * points;
			
			return;
		}
		
		void endCombo() {
			comboNum = 0;
			
			return;
		}
		
		void setName(string characterName) {
			name = characterName;
			
			return;
		}
		
		void updateLevel(int num) {
			level = num;
			
			return;
		}
		
		void updatePos_x(int num) {
			pos_x = num;
			
			return;
		}
		
		void updatePos_y(int num) {
			pos_y = num;
			
			return;
		}
		
		void updateCoins(int num) {
			coins = num;
			
			return;
		}
		
		void forward() {
			pos_x++;
			
			return;
		}
		
		void backward() {
			pos_x--;
			
			return;
		}
		
		void fireFlower() {
			if (isFire == false)
				isFire = true;
			else
				score += 1600;
		
			return;
		}
		
		void invincibleStar() {
			if (isStarry == false)
				isStarry = true;
			else
				score += 1600;
			
			return;
		}
		
		void printStatus() {
			cout << "Position: level: " << level 
				 << "\tx: " << pos_x << "\ty: " << pos_y << "\n"
				 << "Character Name: " << name << "\n"
				 << "Coins:\t" << coins << "\n"
				 << "Lives:\t" << lives << "\n"
				 << "Combo#:\t" << comboNum << "\n"
				 << "Score:\t" << score << "\n";
			if (isBig) 
				cout << "is Big?: Yes\n";
			else
				cout << "is Big?: No\n";
			
			if (isFire) 
				cout << "has Fire Flower?: Yes\n";
			else
				cout << "has Fire Flower?: No\n";
				
			if (isStarry) 
				cout << "is Starry?: Yes\n";
			else
				cout << "is Starry?: No\n";
				
			cout << "\n\n\n";
		}
		
		bool isLarge() {
			if (isBig)
				return true;
			else
				return false;
		}
		
};	

#endif
