#include <iostream>
#include <string>
#include "personType.h"
#include "personType.cpp"
#include "doctorType.h"
#include "billType.h"
#include "dateType.h"
#include "patientType.h"

using namespace std;

void showMenuBase();
void showMenuUpdate();

int main() {
	int menuChoice;
	int IDcount = 2;
	patientType patientRecord(1);
	patientType* root = &patientRecord;
	patientType* workingRecord = &patientRecord;
	
	do {
		showMenuBase();
		cout << "Enter your choice:  ";
		cin >> menuChoice;
		cout << endl;
		
		switch (menuSelection)
			case 1:
				break;
			case 2:
				break;
			case 3:
				int selection;
				
				do {
					showMenuUpdate();
					cout << "Enter your choice:  ";
					cin >> selection;
					cout << endl;
					
					switch (selection)
						case 1:
							string first;
							string last;
							
							cout << "Enter patient's first name: ";
							cin >> first;
							cout << "\nEnter the patient's last name: ";
							cin >> last;
							cout << endl;
							
							workingRecord.setName(first, last);
							break;
						case 2:
							int y;
							int m;
							int d;
							
							cout << "Enter updated birthdate:\n"
								 << " Year:\t";
							cin >> y;
							cout << endl
								 << " Month:\t";
							cin >> m;
							cout << endl
								 << " Day:\t";
							cin >> d;
							cout << endl;
							
							workingRecord.setBirthDate(y, m ,d);
							break;
						case 3:
							int y;
							int m;
							int d;
							
							cout << "Enter updated admittance date:\n"
								 << " Year:\t";
							cin >> y;
							cout << endl
								 << " Month:\t";
							cin >> m;
							cout << endl
								 << " Day:\t";
							cin >> d;
							cout << endl;
							
							workingRecord.setAdmitDate(y, m ,d);
							break;
						case 4:
							int y;
							int m;
							int d;
							
							cout << "Enter updated discharge date:\n"
								 << " Year:\t";
							cin >> y;
							cout << endl
								 << " Month:\t";
							cin >> m;
							cout << endl
								 << " Day:\t";
							cin >> d;
							cout << endl;
							
							workingRecord.setDischargeDate(y, m ,d);
							break;
						case 5:
							int num;
							
							cout << "Enter patient ID number: ";
							cin >> num;
							cout << endl;
							
							workingRecord.setPatientID(num);
							break;
						case 9:
							cout << "Now returning to the main menu...\n";
							break;
						default:
							cout << "Invalid entry, please try again\n";
				} while (selection != 9);
				break;
			case 4:
				string first;
				string last;
				string specialty;
							
				cout << "Enter the doctor's first name: ";
				cin >> first;
				cout <<"\nEnter the doctor's last name: ";
				cin >> last;
				cout << "\nEnter the doctor's specialty: ";
				cin >> specialty;
				cout << endl;
							
				workingRecord.setAttendingPhys(first, last, specialty);
				break;
			case 5:
				int selection;
			
				do {
					showMenuCharges();
					cin >> selection;
					cout << endl;
					
					switch (selection)
						case 1:
							int charges;
						
							cout << "Enter the new pharmacy charges: ";
							cin >> charges;
							cout << endl;
							
							workingRecord->patientBill.addPharmCharge(charges);
							break;
						case 2:
							int charges;
						
							cout << "Enter the new doctor's fees: ";
							cin >> charges;
							cout << endl;
							
							workingRecord->patientBill.addDocFee(charges);
							break;
						case 3:
							int charges;
						
							cout << "Enter the new room charges: ";
							cin >> charges;
							cout << endl;
							
							workingRecord->patientBill.addRoomCharge(charges);
							break;
						case 9:
							cout << "Exiting to main menu...\n";
				} while (selection != 9);
				break;
			case 6:
				break;
			case 9:
				cout << "Now exiting the program...\n\n\n\n";
				break;
			default:
				cout << "Invalid entry, please try again\n";
		
	} while (menuSelection != 9);
	
	return 0;
}

void showMenuBase() {
	cout << "*************************************\n"
		 << " 1: Create a Patient Record\n"
		 << " 2: Select a Patient Record\n"
		 << " 3: Update Patient Information\n"
		 << " 4: Assign a Doctor to the Patient\n"
		 << " 5: Assign Charges to Patient Bill\n"
		 << " 6: Print Patient Record\n"
		 << " 9: Exit Program\n"
		 << "*************************************\n\n";
}

void showMenuUpdate() {
	cout << "*************************************\n"
		 << " 1: Update Patient Name\n"
		 << " 2: Update Patient Birth Date\n"
		 << " 3: Update Patient Admit Date\n"
		 << " 4: Update Patient Discharge Date\n"
		 << " 5: Update Patient ID Number\n"
		 << " 9: Return to Main Menu\n"
		 << "*************************************\n\n";
}

void showMenuCharges() {
	cout << "*************************************\n"
		 << " 1: Add Pharmacy Charges\n"
		 << " 2: Add Doctor's Fees\n"
		 << " 3: Add Room Charges\n"
		 << " 9: Return to Main Menu\n"
		 << "*************************************\n\n";
}
