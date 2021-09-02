#ifndef checkupType_CPP
#define checkupType_CPP

#include <iostream>

using namespace std;

class checkup {
	protected:
		int patientNum;
		int pressureSys;
		int pressureDia;
		int ldl;
		int hdl;
		
	public:
		checkup() {
			patientNum = 0;
			pressureSys = 0;
			pressureDia = 0;
			ldl = 0;
			hdl = 1;
		}

		void setSysPress(int num) {
			pressureSys = num;
		}
		
		void setDiaPress(int num) {
			pressureDia = num;
		}

		void setLDL(int num) {
			ldl = num;
		}

		void setHDL(int num) {
			hdl = num;
		}

		void setPatientNum(int num) {
			patientNum = num;
		}
		
		int getSysPress() {
			return pressureSys;
		}
		
		int getDiaPress() {
			return pressureDia;
		}

		int getLDL() {
			return ldl;
		}

		int getHDL() {
			return hdl;
		}

		int getPatientNum() {
			return patientNum;
		}
		
		void showValues() {
			cout << "Patient Number:\t" << patientNum << "\n"
				 << "Blood Pressure:\t" << pressureSys << " / " << pressureDia << "\n"
				 << "LDL Number:    \t" << ldl << "\n"
				 << "HDL Number:    \t" << hdl << "\n" << endl;
		}
		
		void computeRatio() {
			cout << "Cholesterol Ratio is: " << ldl/hdl << endl;
		}
		
		void explainRatio() {
			cout << "Good health includes a proper balance between low-density lipids (LDLs), \n"
				 << "known as \"bad cholesterol\", and high-density lipids (HDLs), known as \n"
				 << "\"good cholesterol\". The optimum ratio is 3.5 and lower.\n\n"
/*				 << "High-density lipids are preferrable over low-density ones \n"
				 << "because the more compact the lipid coils are the less likely they \n"
				 << "are to cling to one another in the blood vessels which causes clots." << endl;
*/		
				 << endl;
		}
		
	};
		
		


#endif

