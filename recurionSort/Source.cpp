#include <iostream>
using namespace std;

int counter = 0;
const int SIZE = 10;
template <typename T>
void ArrayFill(T arr[], T SIZE);
template <typename T>
void ArrayPrint(T arr[], T SIZE);
template <typename T>
void ArraySort(T arr[], T left, T right, T counter);

void main()
{
	int arr[SIZE];
	double arr2[SIZE];
	int counter = 0;
	cout << "array is: "; ArrayFill(arr, SIZE); ArrayPrint(arr, SIZE);
	ArraySort(arr, 0, SIZE - 1, counter);
	cout << endl;
	ArrayPrint(arr, SIZE);
	cout << endl << counter;
}
template <typename T>
void ArrayFill(T arr[], T SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10;
	}
}
template <typename T>
void ArrayPrint(T arr[], T SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
}
template <typename T>
void ArraySort(T arr[], T left, T right, T counter)
{
	int i, j, x, temp;
	i = left;
	j = right;
	x = arr[(left + right) / 2];
	do
	{

		while ((arr[i] < x) && (i < right))
		{
			i++;
			counter++;
		}
		while ((x < arr[j]) && (j > left))
		{
			j--;
			counter++;
		}
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
		counter++;
	} while (i <= j);
	if (left < j) ArraySort(arr, left, j, counter);
	if (i < right)ArraySort(arr, i, right, counter);
}

