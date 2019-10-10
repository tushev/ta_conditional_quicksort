#pragma once

bool smaller_or_equal(int a, int b)
{
	// check divisibility by 3
	bool a_div = (a % 3 == 0);
	bool b_div = (b % 3 == 0);

	if (a_div == b_div)
		return a <= b;

	// if b is not divisible by 3 - a "is smaller" (a<=b)
	if (!b_div) return true;
	// => so here b is divisible by 3

	//if a is not divisible by 3 - a "is NOT smaller"(a>b)
	if (!a_div) return false;
	// => so here b is divisible by 3

	
}

int partition_conditional(vector<int> & arr, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);  // index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{

		if (smaller_or_equal(arr[j],pivot))
		{
			i++;    // increment index of smaller element 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[(int)i + 1], arr[high]);
	return (i + 1);
}


void quick_sort(vector<int> & arr, int low, int high)
{
	if (low < high)
	{
		// pi is partitioning index, arr[p] is now at right place 
		int pi = partition_conditional(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}