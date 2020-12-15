#include <bits/stdc++.h>

using namespace std;

const int D = 100;

template <class T>
class SelectionSort 
{
private:
	int n;
	T arr[D];
public:
	SelectionSort() 
	{
		n = 0;
	}
	void setArray() 
	{
		cout << "Enter size: "; cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Enter element number - " << i + 1 << ": ";
			cin >> arr[i];
		}
	}
	void PrintArray()
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	void Sort() 
	{  // sort using selection sort algorithm
		int i, j, min_idx;
		for (i = 0; i < n - 1; i++) {
			min_idx = i;
			for (j = i + 1; j < n; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;
			swap(arr[min_idx], arr[i]);
		}
	}
};

int main() 
{
	while (true) 
	{
		cout << "Which array do you want to sort??\n";
		cout << "1 for integer array\n2 for float array\n0 to exit\n:";
		int choice = 0;
		cin >> choice;
		if (choice == 1) 
		{
			SelectionSort<int> int_sort;
			int_sort.setArray();
			cout << "Before Sorting: ";
			int_sort.PrintArray();
			int_sort.Sort();
			cout << "After Sorting: ";
			int_sort.PrintArray();
		}
		else if (choice == 2) 
		{
			SelectionSort<float> float_sort;
			float_sort.setArray();
			cout << "Before Sorting: ";
			float_sort.PrintArray();
			float_sort.Sort();
			cout << "After Sorting: ";
			float_sort.PrintArray();
		}
		else if (choice == 0)
			break;
		else
			cout << "INVALID CHOICE. Try Again.\n";
	}
	return 0;
}