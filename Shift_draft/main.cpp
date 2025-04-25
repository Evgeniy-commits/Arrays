#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

#define tab   "\t"
#define Escape 27
#define UpArrow 72
#define DownArrow 80
#define LeftArrow 75
#define RightArrow 77

void main()
{
	setlocale(LC_ALL, "");
	const int ROWS = 5;
	const int COLS = 6;
	const int n = ROWS * COLS;
	int arr2d[ROWS][COLS], arr[n];
	int maxRand = 0, minRand = n;
	int buf, shift = COLS, k = 0;
	char key;
	if (minRand > maxRand) minRand ^= maxRand ^= minRand ^= maxRand;
	for (int k = 0; k < n; k++)
	{
		arr[k] = rand() % (maxRand - minRand) + minRand;
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr2d[i][j] = arr[k];
			cout << arr2d[i][j] << tab;
			k++;
		}
		cout << endl;
	}
	cout << endl;
	k = 0;
	while (true)
	{
		key = _getch();
		if (key == Escape) break;
		switch (key)
		{
		case UpArrow:

			for (int i = 0; i < shift; i++)
			{
				buf = arr[0];
				for (int i = 1; i < n; i++)
				{
					arr[i - 1] = arr[i];
				}
				arr[n - 1] = buf;
			}
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					arr2d[i][j] = arr[k];
					k++;
				}
			}
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					cout << arr2d[i][j] << tab;
				}
				cout << endl;
			}
			k = 0;
			cout << endl;
			break;

		case DownArrow:
			for (int i = 0; i < shift; i++)
			{
				buf = arr[n - 1];
				for (int i = n - 1; i > 0; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[0] = buf;
			}
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					arr2d[i][j] = arr[k];
					k++;
				}
			}
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					cout << arr2d[i][j] << tab;
				}
				cout << endl;
			}
			k = 0;
			cout << endl;
			break;

		case LeftArrow:
			for (int i = 0; i < shift / COLS; i++)
			{
				for (int i = 0; i < ROWS; i++)
				{
					buf = arr2d[i][0];
					for (int j = 1; j < COLS; j++)
					{
						arr2d[i][j - 1] = arr2d[i][j];
						cout << arr2d[i][j] << tab;
					}
					arr2d[i][COLS - 1] = buf;
					cout << arr2d[i][COLS - 1] << endl;
				}
			}
			cout << endl;
			break;
		case RightArrow:
			for (int i = 0; i < shift; i++)
			{
				for (int i = 0; i < ROWS; i++)
				{
					buf = arr2d[i][COLS - 1];
						for (int j = COLS - 1; j > 0; j--)
						{
							arr2d[i][j] = arr2d[i][j - 1];
						}
						buf = arr2d[i][0];
				}
			}

			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					cout << arr2d[i][j] << tab;
				}
				cout << endl;
			}
			cout << endl;
			break;
		}
	}
}
