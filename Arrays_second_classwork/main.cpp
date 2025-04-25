#include<iostream>
//#include<Windows.h>
using namespace std;

//#define GENERATION
//#define MIN_TO_MAX
#define MIN_TO_MAX_CLASS

void main()
{
	setlocale(LC_ALL, "");

#ifdef GENERATION
	const int n = 5;
	double sum = 0, max, min;
	int arr[n];
	int maxRand, minRand;
	do
	{
		cout << "Введите минимум "; cin >> minRand;
		cout << "Введите максимум "; cin >> maxRand;
		if (minRand > maxRand) cout << "Минимальное должно быть меньше";
		if (minRand == maxRand) cout << "Числа должны быть разные";
	} while (minRand >= maxRand);

	/*if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}*/
	for (int i = 0; i < n; i++)
	{		
		arr[i] = rand() % (maxRand - minRand) + minRand;
		sum += arr[i];
	}
	max = min = arr[0];
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
		min > arr[i] ? min = arr[i] : max < arr[i] ? max = arr[i] : 0;
	}
	cout << endl;
	for (int i = n - 1; i >= 0; i--) cout << arr[i] << " ";
	cout << endl;
	cout << "Сумма элементов массива = " << sum << "\nСреднее арифметическое элементов массива = " << sum / n << endl;
	cout << "Минимальное значение элемента = " << min << "\n" << "Ммаксимальное значение элемента = " << max << endl;
#endif // GENERATION

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