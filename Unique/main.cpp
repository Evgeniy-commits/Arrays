#include<iostream>
using namespace std;

#define Unique
//#define MIN_TO_MAX
//#define MIN_TO_MAX_CLASS

void main()
{
	setlocale(LC_ALL, "");

#ifdef Unique
	const int n = 10;
	int arr[n];
	int maxRand = 70, minRand = 80;
	do
	{
		//cout << "Введите минимум "; cin >> minRand;
		//cout << "Введите максимум "; cin >> maxRand;
		if (minRand > maxRand) minRand ^= maxRand ^= minRand ^= maxRand;
		if (minRand == maxRand) cout << "Числа должны быть разные";
	} while (minRand >= maxRand);

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		for (int j = 0; j <= i; j++)
		{
			while (arr[j] == arr[i] && i != j)
			{
				arr[i] = rand() % (maxRand - minRand) + minRand;
				j = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
    }
	cout << endl;

#endif // Unique

#ifdef MIN_TO_MAX
	const int n = 7;
	int arr[n];
	int buf = 0;
	int maxRand, minRand;
	do
	{
		cout << "Введите минимум "; cin >> minRand;
		cout << "Введите максимум "; cin >> maxRand;
		if (minRand > maxRand) cout << "Минимальное должно быть меньше";
		if (minRand == maxRand) cout << "Числа должны быть разные";
	} while (minRand >= maxRand);

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			buf = arr[i];
			if (arr[i + 1] < arr[i])
			{
				arr[i] = arr[i + 1];
				arr[i + 1] = buf;
			}
		}
		//cout << arr[i] << " ";
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
#endif // MIN_TO_MAX

#ifdef MIN_TO_MAX_CLASS
	const int n = 15;
	int arr[n];
	int buf = 0;
	int maxRand, minRand;
	do
	{
		cout << "Введите минимум "; cin >> minRand;
		cout << "Введите максимум "; cin >> maxRand;
		if (minRand > maxRand) cout << "Минимальное должно быть меньше";
		if (minRand == maxRand) cout << "Числа должны быть разные";
	} while (minRand >= maxRand);

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) // счетчик i 
	{
		for (int j = i + 1; j < n; j++) // j перебирает э-ты в поисках мин значения
		{
			if (arr[j] < arr[i])
			{
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
#endif // MIN_TO_MAX_CLASS
}