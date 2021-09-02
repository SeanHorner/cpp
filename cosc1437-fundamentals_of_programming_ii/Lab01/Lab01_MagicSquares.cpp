#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <iostream>

using namespace std;

void print(int arr[3][3]);
void fillUp(int arr[3][3]);
bool testMagic(int arr[3][3]);

int main()
{ 
	long long countLimit;
	long long count = 0;
	int magicCount = 0;
	
	srand(time(0));
	
	cout << "How many squares would you like to generate? ";
	cin >> countLimit;
	cout << endl;
	
	while (count < countLimit)
	{
		int square[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	
		fillUp(square);
			
		if (testMagic(square))
		{
			magicCount++;
			cout << endl;
			cout << "Trial #" << count << endl;
			cout << "Magic Square #" << magicCount << endl << endl;
			print(square);
			cout << endl << endl;
		}
		print(square);
		count++;
	}
	
	return 0;
}

void print(int arr[3][3])
{
	for (int k = 0; k < 3; k++)
	{
		for (int l = 0; l < 3; l++)
			cout << " " << arr[k][l];
		cout << endl;
	}
	
	return;
}

void fillUp(int arr[3][3])
{
	int m;
	int n;
	int count = 1;
		
	for (count = 1; count < 10; )
	{
		m = rand() % 3;
		n = rand() % 3;
		cout << "square[" << m << "][" << n << "]" << endl;
		if (arr[m][n] == -1)
		{
			arr[m][n] = count;
			count++;
		}
	};
	
	return;
}

bool testMagic(int arr[3][3])
{
	int row1 = arr[0][0] + arr[0][1] + arr[0][2];
	int row2 = arr[1][0] + arr[1][1] + arr[1][2];
	int row3 = arr[2][0] + arr[2][1] + arr[2][2];
	
	int col1 = arr[0][0] + arr[1][0] + arr[2][0];
	int col2 = arr[0][1] + arr[1][1] + arr[2][1];
	int col3 = arr[0][2] + arr[1][2] + arr[2][2];
	
	int diag1 = arr[0][0] + arr[1][1] + arr[2][2];
	int diag2 = arr[0][2] + arr[1][1] + arr[2][0];
	
	if (!(row1 == row2 && row2 == row3))
		return false;
			
	if (!(col1 == col2 && col2 == col3))
		return false;
		
	if (!(diag1 == diag2))
		return false;
			
	if (!(row1 == col1 && row1 == diag1))
		return false;

	return true;
		
}
