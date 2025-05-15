#include<iostream>
using namespace std;

//#define ARR2D_SORT_FUNCTION
//#define ARR2D_UNIQUE_FUNCTION
#define ARR2D_REPEAT_FUNCTION
#define tab "\t"
const int ROWS = 5;
const int COLS = 4;
int randomArr2D(int Arr2D[ROWS][COLS]);
int printArr2D(int Arr2D[ROWS][COLS]);
int sortArr2D(int Arr2D[ROWS][COLS]);
int uniqueArr2D(int Arr2D[ROWS][COLS]);
int repeatArr2D(int Arr2D[ROWS][COLS], int arr[ROWS * COLS]);

void main()
{
	setlocale(LC_ALL, "");

#ifdef ARR2D_SORT_FUNCTION
	int Arr2D[ROWS][COLS];
	randomArr2D(Arr2D);
	printArr2D(Arr2D);
	cout << endl;
	sortArr2D(Arr2D);
	printArr2D(Arr2D);
#endif // ARR2D_SORT_FUNCTION

#ifdef ARR2D_UNIQUE_FUNCTION
	int Arr2D[ROWS][COLS];
	uniqueArr2D(Arr2D);
	printArr2D(Arr2D);
#endif // ARR2D_UNIQUE_FUNCTION

#ifdef ARR2D_REPEAT_FUNCTION
	int Arr2D[ROWS][COLS];
	int arr[ROWS * COLS];
	randomArr2D(Arr2D);
	printArr2D(Arr2D);
	cout << endl;
	repeatArr2D(Arr2D, arr);
#endif // ARR2D_REPEAT_FUNCTION
}

int randomArr2D(int Arr2D[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			Arr2D[i][j] = rand() % 10;
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
int uniqueArr2D(int Arr2D[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool unique;
			do
			{
				Arr2D[i][j] = rand() % (ROWS * COLS);
				unique = true;
				for (int k = 0; k <= i; k++)
				{
					for (int l = 0; l < (k == i ? j : COLS); l++)
					{
						if (Arr2D[i][j] == Arr2D[k][l])
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
	return 0;
}
int repeatArr2D(int Arr2D[ROWS][COLS], int arr[ROWS * COLS])
{
	int k = 0;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			arr[k] = Arr2D[i][j];
			k++;
		}
	for (int i = 0; i < ROWS * COLS; i++)
	{
		int count = 0;
		int number = i;
		for (int j = 0; j < ROWS * COLS; j++)
		{
			if (arr[j] == number)
			{
				count += 1;
				arr[j] = ROWS * COLS;
			}
		}
		if (count > 1 && number != ROWS * COLS) cout << "Число " << number << " встречается " << count << " раза" << endl;
	}
	return 0;
}