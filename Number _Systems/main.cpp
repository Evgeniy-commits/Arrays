#include<iostream>
#include<Windows.h>
using namespace std;

//#define HW_TASK_SHIFT_RIGHT
//#define NUMBER_SYSTEM

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");

#ifdef HW_TASK_SHIFT_RIGHT

	const int n = 20;
	int arr[n];
	int Shift;

	for (int i = 0; i < n; i++)
		{
			arr[i] = { i };
			cout << arr[i] << tab;
		}
		cout << endl;

	cout << "Введите сдвиг: "; cin >> Shift;
	
	for (int i = 0; i < Shift; i++)

	{
		int buffer = arr[n - 1];

		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;

		Sleep(500);
		system("CLS");
		
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << tab;
		}
		cout << endl;
	}
#endif // HW_TASK_SHIFT_RIGHT

#ifdef NUMBER_SYSTEM
	long long number;
	cout << "Введите число: "; cin >> number;
	long long buf_number = number;
	cout << "DEC " << number << " = " << number << endl;
	int digit = log2(number);
	cout << number << " = " << "BIN " ;
	for (; digit >= 0; digit--)
	{
		buf_number >>= digit;
		buf_number &= 1;
		cout << buf_number;
		buf_number = number;
	}
	cout << endl;
	digit = log2(number) / log2(16);
	cout << number << " = " << "HEX ";
	for (; digit >= 0; digit--)
	{
		buf_number >>= 4 * digit;
		buf_number &= 15;
		switch (buf_number)
			{
				case 10: cout << "A"; break;
				case 11: cout << "B"; break;
				case 12: cout << "C"; break;
				case 13: cout << "D"; break;
				case 14: cout << "E"; break;
				case 15: cout << "F"; break;
				default: cout << buf_number;
			}
		buf_number = number;
	}
#endif // NUMBER_SYSTEM


}