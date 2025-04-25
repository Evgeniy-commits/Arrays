#include<iostream>
using namespace std;
#define tab   "\t"

void main()
{
	setlocale(LC_ALL, "");
	const int ROWS = 5;
	const int COLS = 6;
	int arr[ROWS][COLS];
	int maxRand = 0, minRand = ROWS * COLS;
	int buf, shift;

	if (minRand > maxRand) minRand ^= maxRand ^= minRand ^= maxRand;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
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

	// СДВИГ ПО СТОЛБЦАМ
	//cout << "введите сдвиг "; cin >> shift;
	//if (shift <= 0)
	//{
	//	shift = abs(shift);
	//	for (int i = 0; i < shift; i++)
	//	{

	//		for (int i = 0; i < ROWS; i++)
	//		{
	//			buf = arr[i][0];
	//			for (int j = 1; j < COLS; j++)
	//				arr[i][j - 1] = arr[i][j];
	//			arr[i][COLS - 1] = buf;
	//		}
	//	}
	//	// вывод сдвинутого массива
	//	for (int i = 0; i < ROWS; i++)
	//	{
	//		for (int j = 0; j < COLS; j++)
	//		{
	//			cout << arr[i][j] << tab;
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//else if (shift > 0)
	//{
	//	for (int i = 0; i < shift; i++)
	//	{
	//		for (int i = 0; i < ROWS; i++)
	//		{
	//			buf = arr[i][COLS - 1];

	//			for (int j = COLS - 1; j > 0; j--)
	//			{
	//				arr[i][j] = arr[i][j - 1];
	//			}
	//			arr[i][0] = buf;
	//		}
	//	}
	//	// вывод сдвинутого массива
	//	for (int i = 0; i < ROWS; i++)
	//	{
	//		for (int j = 0; j < COLS; j++)
	//		{
	//			cout << arr[i][j] << tab;
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}

	// СДВИГ ПО ЭЛЕМЕНТАМ
	cout << "введите сдвиг "; cin >> shift;
	if (shift <= 0)
	{
		shift = abs(shift);
		for (int i = 0; i < shift; i++)
		{
			int bufStart = arr[0][0];
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 1; j < COLS; j++)
				{
					i >= 0 && i < ROWS - 1 ? buf = arr[i + 1][0] : buf = bufStart;
					arr[i][j - 1] = arr[i][j];
					arr[i][j] = buf;
				}
			}
		}		
		// вывод сдвинутого массива
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << arr[i][j] << tab;
			}
			cout << endl;
		}
		cout << endl;
	}
	else if (shift > 0)
	{
		for (int i = 0; i < shift; i++)
		{
			int bufStart = arr[ROWS - 1][COLS - 1];
			for (int i = 0; i < ROWS; i++)
			{
				buf = arr[i][COLS - 1];
				for (int j = COLS - 1; j > 0; j--)
				{   
					arr[i][j] = arr[i][j - 1];
					arr[i][0] = buf;
				}
			}
		}
		// вывод сдвинутого массива
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << arr[i][j] << tab;
			}
			cout << endl;
		}
		cout << endl;
	}
	//const int n = 10;
	//int arr[n];
	//int maxRand = 0, minRand = 5, count;

	//if (minRand > maxRand) minRand ^= maxRand ^= minRand ^= maxRand;
	//for (int i = 0; i < n; i++)
	//{
	//	arr[i] = rand() % (maxRand - minRand) + minRand;
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << endl;

	//for (int i = 0; i < n; i++)
	//{
	//	count = 0;
	//	int number = i;
	//	for (int j = 0; j < n; j++)
	//	{
	//		if (arr[j] == number)
	//		{
	//			count += 1;
	//			arr[j] = maxRand;
	//		}
	//	}
	//	if (count > 1 && number != maxRand) cout << "Число " << number << " встречается " << count << " раза" << endl;
	//}
}