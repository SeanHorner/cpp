#include <stdio>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct playerRecord {
	string name;
	string postion;
	int touchdowns;
	int catches;
	int yardsPassing;
	int yardsReceiving;
	int yardsRushing;
}

void showMenu();
void parseMenu(int choice);
int nameSearch();
int selectPlayer(struct playerRecord *selectedPlayer);
void updateStr(struct playerRecord *selectedRecord, int num);
void updateStat(struct playerRecord *selectedRecord, int num);
void printStats(struct playerRecord *selectedRecord, int num);
void exitProgram();

int main() {
	showMenu();
	
	cin
	
	
}

void showMenu() {
	cout << "************************************************************************************************"
		 << " 1: Search Player number by Name\n"
		 << " 2: Choose A Player (by Number)\n"
		 << " 3: Update Player Name\n"
		 << " 4: Update Player Position\n"
		 << " 5: Update Player Stat: Touchdowns\n"
		 << " 6: Update Player Stat: Catches\n"
		 << " 7: Update Player Stat: Passing Yards\n"
		 << " 8: Update Player Stat: Receiving Yards\n"
		 << " 9: Update Player Stat: Rushing Yards\n"
		 << "99: Exit Program\n"
		 << "************************************************************************************************";
}

void parseMenu(struct playerRecord *selectedRecord, int choice) {
	switch (choice)	{
		case 1:
			printPlayers();
			break;
		case 2:
			selectPlayer();
			break;
		case 3:
			updateStr(*selectedRecord, 1);
			break;
		case 4:
			updateStr(*selectedRecord, 2);
			break;
		case 5:
			updateStat(*selectedRecord, 1);
			break;
		case 6:
			updateStat(*selectedRecord, 2);
			break;
		case 7:
			updateStat(*selectedRecord, 3);
			break;
		case 8:
			updateStat(*selectedRecord, 4);
			break;
		case 9:
			updateStat(*selectedRecord, 5);
			break;
		case 99:
			cout << "Exiting Program...";
			break;
		default:
			cout << "I'm sorry, that wasn't one of the options, please choose again: ";
			cin >> choice;
			cout << endl;
	}

	return;
}

int selectPlayer() {
	
	cout << "Please choose a 

int nameSearch(struct playerRecord *record) {
	string searchName;
	
	cout << "Please enter desired the player's name:\n";
	cin >> searchName;
	cout << endl;
	
	for (int i = 0; i < 10; i++) {
		if (*record[i]->name == searchName;)
			return i;
	}
	
	return 99;
}

void updateStr(struct playerRecord *selectedRecord, int num) {
	string newStr;
	
	if (num == 1) {
		cout << "Please enter player's new name: ";
		cin >> newStr;
		cout << endl;
		
		selectedRecord->name = newStr;
	}
	else if (num == 2) {
		cout << "Please enter player's new position: ";
		cin >> newStr;
		cout << endl;
		
		selectedRecord->position = newStr;
	}
	
	return;
}

void updateStat(struct playerRecord *selectedRecord, int num) {
	int newStat;
	
	switch(num) {
		case 1:
			cout << "Please enter player's new thouchdown stat: ";
			cin >> newStat;
			cout << endl;
			
			*selectedRecord->touchdowns = newStat;
		case 2:
			cout << "Please enter player's new catches stat: ";
			cin >> newStat;
			cout << endl;
			
			*selectedRecord->catches = newStat;
		case 3:
			cout << "Please enter player's new passing yards stat: ";
			cin >> newStat;
			cout << endl;
			
			*selectedRecord->yardsPassing = newStat;
		case 4:
			cout << "Please enter player's new receiving yards stat: ";
			cin >> newStat;
			cout << endl;
			
			*selectedRecord->yardsReceiving = newStat;
		case 5:
			cout << "Please enter player's new rushing yards stat: ";
			cin >> newStat;
			cout << endl;
			
			*selectedRecord->yardsRushing = newStat;
		default:
			cout << "Great Scott! Thats 1.21 jig-a-watts!";
	}
}
			
void printStats(struct playerRecord *selectedRecord) {
	cout << "Player Name:  " << *selectedRecord->name << "\n";
	cout << "Player Position:  " << *selectedRecord->position << "\n";
	cout << "Player Touchdowns:  " << *selectedRecord->touchdowns << "\n";
	cout << "Player Catches:  " << *selectedRecord->catches << "\n";
	cout << "Player Passing Yards:  " << *selectedRecord->yardsPassing << "\n";
	cout << "Player Receiving Yards:  " << *selectedRecord->yardsReceiving << "\n";
	cout << "Player Rushing Yards:  " << *selectedRecord->yardsRushing << "\n\n";
}
	
