#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int square[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	int m;
	int n;
	int count = 1;
	
	srand(time(NULL));
		
	do
	{
		m = rand() % 3;
		n = rand() % 3;
		cout << "square[" << m << "][" << n << "] \n";
		if (square[m][n] == -1)
		{
			square[m][n] = count;
			count++;
		}
	} while (count < 11);
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << square[i][j];
		cout << endl;
	}
	
	return 0;
}
