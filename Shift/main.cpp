#include<iostream>
using namespace std;

#define HW_TASK_SHIFT

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
	for (int i = Shift; i < n; i++) cout << arr[i] << " ";
	for (int i = 0; i < Shift; i++) cout << arr[i] << " ";
#endif // HW_TASK_SHIFT
}