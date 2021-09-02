#ifndef doctorType_H
#define doctorType_H

#include <string>
#include "personType.h"
#include "personType.cpp"

using namespace std;

class doctorType : public personType {
	private:
		string specialty;
		
	public:
		string getSpecialty() {
			return specialty;
		}
			
		void setSpecialty(string newSpec) {
			specialty = newSpec;
		}
		
		doctorType (string special) {
			specialty = special;
		}
};

#endif
