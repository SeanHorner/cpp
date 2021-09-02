#ifndef dateType_H
#define dateType_H

#include <iostream>

using namespace std;

class dateType {
	private:
		int year;
		int month;
		int day;
		int hours;
		int mins;
		int secs;
		
	public:
		dateType () {
			year = 0;
			month = 0;
			day = 0;
			hours = 0;
			mins = 0;
			secs = 0;
		}
		
		dateType (int y, int m, int d) {
			year = y;
			month = m;
			day = d;
			hours = 0;
			mins = 0;
			secs = 0;
		}
			
		dateType (int y, int m, int d, int h, int m, int s) {
			year = y;
			month = m;
			day = d;
			hours = h;
			mins = m;
			secs = s;
		}
		
		void setDate (int y, int m, int d) {
			year = y;
			month = m;
			day = d;
		}
		
		void setFullDate (int y, int m, int d, int h, int m, int s) {
			year = y;
			month = m;
			day = d;
			hours = h;
			mins = m;
			secs = s;
		}
		
		void printDate() {
			cout << y << "/" << m << "/" << d;
		}
		
		void printFullDate() {
			cout << y << "/" << m << "/" << d << "  " << h << ":" << m << ":" << s;
		}
	
};

#endif
