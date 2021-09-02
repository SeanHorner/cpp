#ifndef patientType_H
#define patientType_H

#include <iostream>
#include <string>
#include "personType.h"
#include "personType.cpp"
#include "doctorType.h"
#include "billType.h"
#include "dateType.h"

using namespace std;

class patientType : public personType {
	private:
		int patientID;
		doctorType attendingPhys;
		dateType birthDate;
		dateType admitDate;
		dateType dischargeDate;
		patientType* next = NULL;
	
	public:
		patientType() {
			patientID = 0;
			firstName = " ";
			lastName = " ";
			age = 0;
			
			attendingPhys.setName(" ", " ");
			attendingPhys.setSpecialty(" ");
			
			birthDate.setDate(1,1,1901);
			admitDate.setDate(1,1,1901);
			dischargeDate.setDate(1,1,1901);
		}
		
		void setPatientID(int num) {
			patientID = num;
		}
		
		void setAttendingPhys(string first, string last, string special) {
			attendingPhys.setName(first, last);
			attendingPhys.setSpecialty(special);
		}
		
		void setBirthDate(int y, int m, int d) {
			birthDate.setDate(y, m, d);
		}
		
		void setAdmitDate(int y, int m, int d) {
			admitDate.setDate(y, m, d);
		}
		
		void setDischargeDate(int y, int m, int d) {
			dischargeDate.setDate(y, m, d);
		}
		
		void setNextAddr(patientType record) {
			next  = &record;
		}
		
		int getPatientID() {
			return patientID;
		}
		
		void getAttendingPhys() {
			cout << "Attending Physician is : Dr. " 
				 << attendingPhys.getFirstName << " "
				 << attendingPhys.getLastName << "\n"
				 << " with a specialty in : " 
				 << attendingPhys.getSpecialty() << endl;
		}
		
		void getBirthDate() {
			birthDate.printDate();
		}
		
		void getAdmitDate() {
			admitDate.printDate();
		}
		
		void getDischargeDate() {
			dischargeDate.printDate();
		}
		
		&patientType getNextAddr() {
			return &next;
		}
		
};
	
#endif
