#ifndef billType_h
#define billType_h

#include <string>

using namespace std;

class billType {
	private:
		int patientID;
		int pharmCharge;
		int docFee;
		int roomCharge;
		
	public:
		billType () {
			patientID = -1;
			pharmCharge = -1;
			docFee = -1;
			roomCharge = -1;
		}
		
		billType (int a, int b, int c, int d) {
			patientID = a;
			pharmCharge = b;
			docFee = c;
			roomCharge = d;
		}
		
		void setPatientID(int num) {
			patientID = num;
		}
		
		void setPharmCharge (int num) {
			patientID = num;
		}
		
		void setDocFee(int num) {
			docFee = num;
		}
		
		void setRoomCharge(int num) {
			roomCharge = num;
		}
		
		int getPatientID() {
			return patientID;
		}

		int getPharmCharge() {
			return pharmCharge;
		}
		
		int getDocFee() {
			return docFee;
		}
		
		int getRoomCharge() {
			return roomCharge;
		}
		
		int getFullCharges() {
			return pharmCharge + docFee + roomCharge;
		}
		
};

#endif
