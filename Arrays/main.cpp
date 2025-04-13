#include<iostream>
using namespace std;

//#define CLASSWORK_ARRAYS
#define HW_TASK_1

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef CLASSWORK_ARRAYS
	const int n = 5;
	int arr[n] = { 3, 5, 8 };
	//arr[1] = 1024;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif // CLASSWORK_ARRAYS

#ifdef HW_TASK_1
	const int n = 5;
	double sum = 0;
	int arr[n];
	int max, min;
	cout << "Ввведите " << n << " чисел" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << " число: ";
		while (true) 
		{ 
			cin >> arr[i];
			if (arr[i] < 0) cout << "Введите не отрицательное " << i + 1 << " число: ";
			else break;
		}
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
#endif // HW_TASK_1

}