#include<iostream>
using namespace std;

#define tab "\t"
const int ROWS = 5;
const int COLS = 4;

void main()
{
	setlocale(LC_ALL, "");
	int arr[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			arr[i][j] = rand() % 10;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

	/*for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool met_before = false;
			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < (i ? j : COLS); l++)
					if (arr[i][j] == arr[k][l])
					{
						met_before = true;
						break;
					}
			}
			if (met_before) continue;
			int count = 0;
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					if (arr[i][j] == arr[k][l]) count++;
				}
			}
			if (count) cout << "Значение " << arr[i][j] << " повторяется " << count << " раз" << endl;
		}
	}*/

	for (int i = 0; i < ROWS * COLS; i++)
	{
		bool met_before = false;
		for (int j = 0; j < i; j++)
		{
			if (arr[0][i] == arr[0][j])
			{
				met_before = true;
				break;
			}
		}
		if (met_before) continue;
		int count = 0;
		for (int j = i + 1; j < ROWS * COLS; j++)
		{
			if (arr[0][i] == arr[0][j]) count++;
		}
		if (count) cout << "Значение " << arr[0][i] << " повторяется " << count << " раз" << endl;
	}

	cout << "Finita la comedia" << endl;
}
