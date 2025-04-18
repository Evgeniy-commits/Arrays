#include<iostream>
#include <typeinfo>
using namespace std;

//#define CLASSWORK_ARRAYS
//#define HW_TASK_1
//#define CLASSWORK_ARRAYS_AR
#define GENERATION

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
	double sum = 0, max, min;
	double arr[n];
	cout << "Ввведите " << n << " чисел" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << " число: ";
		cin >> arr[i];
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


#ifdef CLASSWORK_ARRAYS_AR
	const int n = 5;
	int arr[n] = { 3, 5, 8 };
	//arr[1] = 1024;

	cout << "Введите элементы масстива: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

#endif // CLASSWORK_ARRAYS_AR

#ifdef GENERATION
	const int n = 50000;
	double sum = 0, max, min;
	int arr[n];
	
	for (int i = 0; i < n; i++)
	{
		do
		{
			arr[i] = rand();
		} while (arr[i] > 10000);
		/*for (;true;)
		{
			arr[i] = rand();
			if (arr[i] < 10000) break;
		}	*/

	sum += arr[i];
	}
	//sum += arr[i];
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
}