#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#include "main.hpp"

size_t defined_array_length;
string input_buffer;

vector<int> input_array;


int main(int argc, char *argv[])
{
	getline(cin, input_buffer);
	{
		stringstream iss(input_buffer);
		iss >> defined_array_length;
	}

	// Read array, regardless of its size
	getline(cin, input_buffer);
	{
		stringstream iss(input_buffer);
		int item;
		while (iss >> item)
			input_array.push_back(item);
	}


	quick_sort(input_array, 0, input_array.size() - 1);


	for (auto i : input_array)
		cout << i << " ";
	cout << endl;

	return 0;
}