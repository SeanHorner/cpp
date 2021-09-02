#include <iostream>
#include "CheckupType.cpp"

using namespace std;

void getData(int i, class checkup* root);

int main() {
	class checkup record[4];
	class checkup *root = &record[0];
	
	for (int i = 0; i < 4; i++) {
		switch (i) {
			case 0:
				cout << "\tEnter the data for the first patient:\n\n";
				break;
			case 1:
				cout << "\tEnter the data for the second patient:\n\n";
				break;
			case 2:
				cout << "\tEnter the data for the thrid patient:\n\n";
				break;
			case 3:
				cout << "\tEnter the data for the fourth patient:\n\n";
				break;
		}		
		
		getData(i, root);
	}
	
	for (int j = 0; j < 4; j++) {
		record[j].showValues();
		cout << "\n";
		record[j].computeRatio();
		cout << "\n";
		record[j].explainRatio();
		cout << "\n\n";
	}
	
	return 0;
}

void getData(int i, checkup* root) {
	int num;
	int sys;
	int dia;
	int ldl;
	int hdl;
	
	cout << "Enter the patient's ID number:             ";
	cin >> num;
	cout << endl;

	cout << "Enter the patient's blood pressure (sys):  ";
	cin >> sys;
	cout << endl;
	
	cout << "Enter the patient's blood pressure (dia):  ";
	cin >> dia;
	cout << endl;
	
	cout << "Enter the patient's LDL number:            ";
	cin >> ldl;
	cout << endl;
			
	cout << "Enter the patient's HDL number:            ";
	cin >> hdl;
	cout << endl;
			
	root[i].setPatientNum(num);
	root[i].setSysPress(sys);
	root[i].setDiaPress(dia);
	root[i].setLDL(ldl);
	root[i].setHDL(hdl);
	
	return;
}
