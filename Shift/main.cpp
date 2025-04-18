#include<iostream>
#include<Windows.h>
using namespace std;

//#define HW_TASK_SHIFT
#define HW_TASK_SHIFT_CLASSWORK

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");

#ifdef HW_TASK_SHIFT
	const int n = 10;
	int arr[n];
	int Shift;

	cout << "Введите сдвиг: ";
	while (true)
	{
		cin >> Shift;
		if (Shift < 0 || Shift >= 10) cout << "Введите не отрицательное число, меньше 10: ";
		else break;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = { i };
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = Shift; i < n; i++)	cout << arr[i] << " ";
	for (int i = 0; i < Shift; i++) cout << arr[i] << " ";
#endif // HW_TASK_SHIFT

#ifdef HW_TASK_SHIFT_CLASSWORK
	const int n = 40;
	int arr[n];
	int Shift;

	for (int i = 0; i < n; i++)
	{
		arr[i] = { i };
		cout << arr[i] << tab;
	}
	cout << endl;

	cout << "Введите сдвиг: "; cin >> Shift;
	// циклический сдвиг массива:
	for (int i = 0; i < Shift; i++)

	{
		int buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[n - 1] = buffer;
		Sleep(100);
		system("CLS");
	    // вывод сдвинутого массива
	    for (int i = 0; i < n; i++)
	    {
		cout << arr[i] << tab;
	    }
	cout << endl;
    }
#endif // HW_TASK_SHIFT_CLASSWORK
}