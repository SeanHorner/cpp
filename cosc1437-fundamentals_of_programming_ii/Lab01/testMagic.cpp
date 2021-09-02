#include <iostream>

using namespace std;

bool testMagic(int arr[3][3]);
void print(int arr[3][3]);

int main()
{
	int square[3][3] = {{9, 1, 6}, {2, 5, 9}, {5, 9, 2}};
	
	print(square);
	cout << testMagic(square);
	
	return 0;
}

bool testMagic(int arr[3][3])
{	
	int row1 = arr[0][0] + arr[0][1] + arr[0][2];
	int row2 = arr[1][0] + arr[1][1] + arr[1][2];
	int row3 = arr[2][0] + arr[2][1] + arr[2][2];
	
	cout << "Rows: " << row1 << "  " << row2 << "  " << row3 << endl << endl;
	
	int col1 = arr[0][0] + arr[1][0] + arr[2][0];
	int col2 = arr[0][1] + arr[1][1] + arr[2][1];
	int col3 = arr[0][2] + arr[1][2] + arr[2][2];
	
	cout << "Cols: " << col1 << "  " << col2 << "  " << col3 << endl << endl;
	
	int diag1 = arr[0][0] + arr[1][1] + arr[2][2];
	int diag2 = arr[0][2] + arr[1][1] + arr[2][0];
	
	cout << "Diags: " << diag1 << "  " << diag2 << endl << endl;
	
	if (row1 == row2 && row2 == row3)
	{
		cout << "Rows are congruent!" << endl;
	}
	else
	{
		return false;
	}
	if (col1 == col2 && col2 == col3)
	{
		cout << "Columns are congruent!" << endl;
	}
	else
	{
		return false;
	}
	if (diag1 == diag2)
	{
		cout << "Diagonals are congruent!" << endl;
	}
	else
	{
		return false;
	}
	if (row1 == col1 && row1 == diag1)
	{
		cout << "And they all match!" << endl;
	}
	else
	{
		return false;
	}
	
	return true;

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

