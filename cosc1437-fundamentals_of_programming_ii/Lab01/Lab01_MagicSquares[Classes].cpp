#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

class square
{
	public:
	int arr[3][3];
	int order = 0;
	int inSeries;
	
	void fill()
	{
		srand(time(NULL));
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = (rand() % 10);
			}
		}
	}
	
	bool testMagic()
	{
		bool rows;
		bool cols;
		bool diags;
		bool match;
	
		int row1 = arr[0][0] + arr[0][1] + arr[0][2];
		int row2 = arr[1][0] + arr[1][1] + arr[1][2];
		int row3 = arr[2][0] + arr[2][1] + arr[2][2];
	
		int col1 = arr[0][0] + arr[1][0] + arr[2][0];
		int col2 = arr[1][0] + arr[1][1] + arr[2][1];
		int col3 = arr[2][0] + arr[2][1] + arr[2][2];
	
		int diag1 = arr[0][0] + arr[1][1] + arr[2][2];
		int diag2 = arr[0][2] + arr[1][1] + arr[2][0];
	
		if (row1 == row2 && row2 == row3)
			rows = true;
		else
		{
			return false;
		}	
			
		if (col1 == col2 && col2 == col3)
			cols = true;
		else
		{
			return false;
		}
		
		
		if (diag1 == diag2)
			diags = true;
		else
		{
			return false;
		}	
			
		if (row1 == col1 && row1 == diag1)
			match = true;
		else
		{
			return false;
		}
	
		if (rows && cols && diags && match)
			return true;
	}
	
	void print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		
		cout << endl;
		cout << "Magic Square Number: " << order << endl;
		cout << "Square Trial: " << inSeries << endl << endl;
	}
	
	~square(){}

};

int main()
{
	long long count = 0;
	long long countLimit;
	int magicCount = 0;
	
	cout << "How many squares would you like to test? ";
	cin >> countLimit;
	cout << endl;
	
	while (count < countLimit)
	{
		new square obj1;
		
		obj1.fill();
		obj1.inSeries = count;
		obj1.print();
		cout << obj1.testMagic();
		
		if (obj1.testMagic())
		{
			magicCount++;
			obj1.order = magicCount;
			obj1.print();
		}
		
		~square();
		count++;
	}
	
	return 0;
}
			
