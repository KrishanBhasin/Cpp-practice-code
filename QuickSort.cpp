#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void quickSortAction(vector<int>& array_in);

int main()
{
	vector<int> testarray;

	for (int i = 0; i < 100; i++)	//make a 100 size array with random ints
	{
		testarray.push_back((rand() % 40)+1);
	}

	quickSortAction(testarray);
	int i = 0;

	for (std::vector<int>::iterator it = testarray.begin(); it != testarray.end(); ++it)				//try switching to the vector counter objects, not my own i
	{
		cout << *it << "\n";
	}

	getchar();
	return 0;
}

void quickSortAction(vector<int>& array_in)
{
	int pivot_position = 0;
	int size_of_array = array_in.size();          //how big is my array?

	pivot_position = rand() % (size_of_array);               // pick an element to be the pivot

	int pivot_value = array_in[pivot_position];			// find the value of the pivot


	vector<int> array_smaller, array_larger;			//arrays to dump data into

	for (int i = 0; i < size_of_array; ++i)				//cycle across the array_in
	{
		if (i == pivot_position)
		{
			i = i;
		}

		else if (array_in[i] < pivot_value)
		{
			array_smaller.push_back(array_in[i]);
		}

		else if (array_in[i] > pivot_value)
		{
			array_larger.push_back(array_in[i]);
		}
		else
		{
			array_smaller.push_back(array_in[i]);
		}
	}

	if (array_smaller.size() != 0)
	{
	quickSortAction(array_smaller);
	}

	if (array_larger.size() != 0)
	{
		quickSortAction(array_larger);
	}

	vector<int> array_out;

	array_out = array_smaller;
	array_out.push_back(pivot_value);
	array_out.insert(array_out.end(), array_larger.begin(), array_larger.end());

	array_in = array_out;
}
