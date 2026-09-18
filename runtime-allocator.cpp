#include "runtime-allocator.h"
#include "DynamicArray.h"
#include <vector>


int main()
{
	DynamicArray<int> array;

	std::vector<int> vArray;


	array.push_back(10);
	array.push_back(23);
	array.push_back(130);
	array.push_back(2390);


	for (int i = 0; i < array.getSize(); i++) {
		std::cout << array.getArray()[i] << " ";
	}

	return 0;
}
