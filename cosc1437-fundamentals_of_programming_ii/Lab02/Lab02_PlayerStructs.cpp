#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct player
{
	string name;
	string position;
	int touchdowns;
	int catches;
	int passingYards;
	int receivingYards;
	int rushingYards;
};

void modifyString(struct player record, int choice, string newString);
void modifyStat(struct player record, int choice, int newStat);
void showMenu();
void showSelection();
void showPlayerStat(struct player record);
void parseMenu(struct player record, int choice);
int searchName(string name);
int outFile(player record[10]);

int main()
{
	int choice;
	int index;
	struct player record[10];
	
	ifstream dataFile;
	dataFile.open("footballPlayersIn.txt");
	
	for (int count = 0; count < 10; count++)
	{
		dataFile >> record[count].name;
		dataFile >> record[count].position;
		dataFile >> record[count].touchdowns;
		dataFile >> record[count].catches;
		dataFile >> record[count].passingYards;
		dataFile >> record[count].receivingYards;
		dataFile >> record[count].rushingYards;
	}
	
	for (int count = 1; count < 10; count++)
		cout << count << ": " << record[count-1].name << "\n";
	cout << "Please select the player from the list: " << endl;
	cin >> index;
	cout << endl;
	
	struct player selectedRecord = record[index];
	
	do
	{
	showMenu();
	cin >> choice;
	cout << endl;
	
	parseMenu(selectedRecord, choice);
	
	} while (choice < 99);
	
	
}

void modifyString(struct player record, int choice, string newString)
{
	switch(choice)
	{
		case 1:
			record.name = newString;
			break;
		case 2:
			record.position = newString;
			break;
		default:
			cout << "Unacceptable choice!";
			break;
	}
	
	return;
}
	
void modifyStat(struct player record, int choice, int newStat)
{	
	switch(choice)
	{
		case 1:
			record.touchdowns = newStat;
			break;
		case 2:
			record.catches = newStat;
			break;
		case 3:
			record.passingYards = newStat;
			break;
		case 4:
			record.receivingYards = newStat;
			break;
		case 5:
			record.rushingYards = newStat;
			break;
		default:
			cout << "Inappropriate option!" << endl;
			break;
	}
	
	return;
}

void showPlayerStat(struct player record)
{
	cout << "Name: " << record.name << "\n";
	cout << "Position: " << record.position << "\n";
	cout << "Touchdowns: " << record.touchdowns << "\n";
	cout << "Catches: " << record.catches << "\n";
	cout << "Passing Yards: " << record.passingYards << "\n";
	cout << "Receiving Yards: " << record.receivingYards << "\n";
	cout << "Rushing Yards: " << record.rushingYards << "\n";
	
	return;
}

void showMenu()
{
	cout << " 1: Change Player Name\n";
	cout << " 2: Change Player Position\n";
	cout << " 3: Change Player Stat: Touchdowns\n";
	cout << " 4: Change Player Stat: Catches\n";
	cout << " 5: Change Player Stat: Passing Yards\n";
	cout << " 6: Change Player Stat: Receiving Yards\n";
	cout << " 7: Change Player Stat: Rushing Yards\n";
	cout << " 8: Show Player Stats\n";
	cout << " 9: Select Different Player\n";
	cout << "99: Exit Program & Save Data\n";
	cout << "Enter your desired option: ";
}

void parseMenu(struct player record[10], int index, int choice)
{
	string newString;
	int	newStat;
	int newIndex;
	
	switch(choice)
	{
		case 1:
			cout << "Enter new player name: ";
			cin >> newString;
			cout << endl;
			modifyString(record[index], 1, newString);
			break;
		case 2:
			cout << "Enter new player position: ";
			cin >> newString;
			cout << endl;
			modifyString(record[index], 2, newString);
			break;
		case 3:
			cout << "Enter new touchdown stat: ";
			cin >> newStat;
			cout << endl;
			modifyStat(record[index], 1, newStat);
			break;
		case 4:
			cout << "Enter new catches stat: ";
			cin >> newStat;
			cout << endl;
			modifyStat(record[index], 2, newStat);
			break;
		case 5:
			cout << "Enter new passing yardage stat: ";
			cin >> newStat;
			cout << endl;
			modifyStat(record[index], 3, newStat);
			break;
		case 6:
			cout << "Enter new receiving yardage stat: ";
			cin >> newStat;
			cout << endl;
			modifyStat(record[index], 4, newStat);
			break;
		case 7:
			cout << "Enter new rushing yardage stat: ";
			cin >> newStat;
			cout << endl;
			modifyStat(record[index], 5, newStat);
			break;
		case 8:
			showPlayerStat(record);
			break;
		case 9:
			cout << "Please select the player from the list:  " << endl;
			cin >> index;
			cout << "\n";
		case 99:
			cout << "Exiting Program Now...";
			outFile(player record[10]);
			break;
		default:
			cout << "That's not an acceptable option,"
				 << "please enter a different option" << endl;
			break;
		}
	return;
}

int searchName(string name, player record[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (name == record[i].name)
			return i;
	}
	
	return 11;
}

int outFile(player record[10])
{
	ofstream outputFile;
	outputFile.open("footballPlayersOut.txt");
	for (int j = 0; j < 10; j++)
	{
		outputFile << record[j].name << " " << record[j].position << " " << record[j].touchdowns
					<< " " << record[j].catches << " " << record[j].passingYards << " "
					<< record[j].receivingYards << " " << record[j].rushingYards << "\n";
	}
	
	return 0;
}