#include <iostream>
#include <string>

using namespace std;

class alienType {
	protected:
		bool isHumanoid;		//is the alien humanoid?
		bool isSentient;		//is the alien sentient?
		int legs;				//how many legs does it have?
		int organSimplicity;	//scale 1-10, how simple are its organs?
		string speciesName;		//name of the species
		
	public:
		alienType() {
			isHumanoid = false;
			isSentient = false;
			legs = 6;
			organSimplicity = 6;
			speciesName = "";
		}
		
		alienType(bool a, bool b, int c, int d) {
			isHumanoid = a;
			isSentient = b;
			legs = c;
			organSimplicity = d;
			speciesName = "";
		}
		
		void output() {
			cout << "This specimen is a " << speciesName << " which ";
			if (isHumanoid)
				cout << "has ";												//humanoid test
			else
				cout << "does not have ";
			cout << "a humanoid form.\nIt ";
			if (isSentient)													//sentience test
				cout << "is ";
			else
				cout << "is not ";
			cout << "a sentient entity, capable of complex moral choices."
				 << "\nIt has " << legs << " ";
			if (legs == 1)													//leg(s) test
				cout << "leg ";
			else
				cout << "legs ";
			cout << "on which it walks.\nAnd if you opened it up,"
				 << " the complexity of its internal organs would rank a "
				 << organSimplicity << " on the eschewia scale.";
		}
			
};

class MartianType : public alienType {
	public:
		MartianType() {
			speciesName = "Martian";
		}
		
		MartianType(bool a, bool b, int c, int d) {
			isHumanoid = a;
			isSentient = b;
			legs = c;
			organSimplicity = d;
			speciesName = "Martian";
		}
};

class JupiterianType : public alienType {
	public:
		JupiterianType() {
				speciesName = "Jupiterian";
		}
		
		JupiterianType(bool a, bool b, int c, int d) {
			isHumanoid = a;
			isSentient = b;
			legs = c;
			organSimplicity = d;
			speciesName = "Jupiterian";
		}
};
