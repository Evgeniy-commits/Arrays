#include<iostream>
//#include <windows.h>
//#include <time.h>
using namespace std;

//#define UNIQUE
//#define REPEATS
//#define ARR2D_SORT
//#define ARR2D_UNIQUE
#define ARR2D_SORT_FUNCTION
#define tab "\t"
const int ROWS = 5;
const int COLS = 4;
int randomArr2D(int Arr2D[ROWS][COLS]);
int printArr2D(int Arr2D[ROWS][COLS]);
int sortArr2D(int Arr2D[ROWS][COLS]);

void main()
{
	setlocale(LC_ALL, "");
#ifdef UNIQUE
	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		bool unique;
		do
		{
			arr[i] = rand() % 10;
			unique = true;
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break;
				}
			}
		} while (!unique);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // UNIQUE

#ifdef REPEATS
	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		bool met_before = false;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				met_before = true;
				break;
			}
		}
		if (met_before) continue;

		int count = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count > 0) cout << "Значение " << arr[i] << " встречается " << count << " раз\n";

	}
#endif // REPEATS

#ifdef ARR2D_SORT
	const int ROWS = 5;
	const int COLS = 4;
	int Arr2D[ROWS][COLS];
	// Заполнение случайными числами
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			Arr2D[i][j] = rand() % 100;
		}
	}
	// вывод исходного массива на экран
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr2D[i][j] << tab;
		}
		cout << endl;
	}


	// Сортировка массива
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				//for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				for (int l = k > i ? 0 : j + 1; l < COLS; l++)
				{
					//arr[i][j] - выбранный элемент
					//arr[k][l] - перебираемый элемент
					if (Arr2D[k][l] < Arr2D[i][j])
						Arr2D[k][l] ^= Arr2D[i][j] ^= Arr2D[k][l] ^= Arr2D[i][j];
				}
			}
		}
	}

	// Вывод после сортировки
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr2D[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;

#endif // ARR2D_SORT

#ifdef ARR2D_UNIQUE
const int ROWS = 5;
const int COLS = 4;
int arr[ROWS][COLS];
for (int i = 0; i < ROWS; i++)
{
	for (int j = 0; j < COLS; j++)
	{
		bool unique;
		do
		{
			arr[i][j] = rand() % (ROWS * COLS);
			unique = true;
			for (int k = 0; k <= i; k++)
			{
				//for (int l = 0; l < (k < i ? COLS : j); l++)
				for (int l = 0; l < (k == i ? j : COLS); l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						unique = false;
						break;
					}
				}
				if (!unique) break;
			}
		} while (!unique);
	}
}
for (int i = 0; i < ROWS; i++)
{
	for (int j = 0; j < COLS; j++)
	{
		cout << arr[i][j] << tab;
	}
	cout << endl;
}
cout << endl;
#endif // ARR2D_UNIQUE

#ifdef ARR2D_SORT_FUNCTION
	int Arr2D[ROWS][COLS];
	randomArr2D(Arr2D);
	printArr2D(Arr2D);
	cout << endl;
	sortArr2D(Arr2D);
	printArr2D(Arr2D);
	//return;
#endif // ARR2D_SORT_FUNCTION
}

int randomArr2D(int Arr2D[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			Arr2D[i][j] = rand() % 100;
	return 0;
}
int printArr2D(int Arr2D[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr2D[i][j] << tab;
		}
		cout << endl;
	}
	return 0;
}
int sortArr2D(int Arr2D[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k > i ? 0 : j + 1; l < COLS; l++)
				{
					if (Arr2D[k][l] < Arr2D[i][j])
						Arr2D[k][l] ^= Arr2D[i][j] ^= Arr2D[k][l] ^= Arr2D[i][j];
				}
			}
		}
	}
	return 0;
}
