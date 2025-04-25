#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	int maxRand = 0, minRand = 5, count;
	
	if (minRand > maxRand) minRand ^= maxRand ^= minRand ^= maxRand;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		count = 0;
		int number = i;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == number)
			{
				count += 1;
				arr[j] = maxRand;
			}
		}
		if (count > 1 && number != maxRand) cout << "Число " << number << " встречается " << count << " раза" << endl;
	}
}