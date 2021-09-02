#include <iostream>
#include "AlienType.cpp"

using namespace std;

int main() {
	MartianType alien1(true, false, 2, 3);
	JupiterianType alien2(false, true, 4, 8);
	
	alien1.output();
	cout << "\n\n";
	alien2.output();

	return 0;
}
