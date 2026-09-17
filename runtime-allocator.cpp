#include "runtime-allocator.h"

using namespace std;


// Constructor
DynamicArray::DynamicArray(int capacity)
{
	m_Capacity = capacity;				// Set capacity to the user's given capacity
	m_Size = 0;							// Initialize the size of array to 0; There is no data stored within yet
	m_Arr = new int[m_Capacity];		// Allocate m_Capacity amount of integers
}

void DynamicArray::pushback(int i)
{
	if (m_Size >= m_Capacity)			// Checks to see if the amount of data in array 
										// is greater than the capacity of the array
	{
		DynamicArray::resize();			// Call the resize function
	}
	m_Arr[m_Size] = i;					// Add the user data to the array at the next available memory slot
	m_Size++;							// Increase the amount of data so that the data cant be overwritten when not intended
}

void DynamicArray::popback()
{
	m_Size--;							//  Make the amount of data 1 less; 
										// That allows future data to be added at the index of the current data
}


void DynamicArray::resize()
{
	m_Capacity *= 2;					// Multply the data size by 2
	
	int* newArr = new int[m_Capacity];	// Make a new array

	for (int i = 0; i < m_Size; i++)	// Loop through the data of the original array
	{
		newArr[i] = m_Arr[i];			// Transfer the data from original array to new array
	}

	m_Arr = newArr;						// Set the original array's data equal to the new array; 
										// This allows the capacity to increase
}

int main()
{
	DynamicArray dynamicArray(2);
	dynamicArray.pushback(20);
	dynamicArray.pushback(12);
	dynamicArray.pushback(32);
	dynamicArray.pushback(124);
	dynamicArray.pushback(12);
	dynamicArray.pushback(142);

	std::cout << "After adding data: \n\n";

	int* array = dynamicArray.getArray();
	std::cout << "Array: " << std::endl;;
	for (int i = 0; i < dynamicArray.getSize(); i++)
	{
		std::cout << i << ": " << array[i] << std::endl;
	}
		
	std::cout << "Size: " << dynamicArray.getSize() << std::endl;
	std::cout << "Capacity: " << dynamicArray.getCapacity() << std::endl;


	dynamicArray.popback();
	dynamicArray.popback();


	std::cout << "===================================\n\n\n";
	std::cout << "After removing data \n\n";
	std::cout << "Array: " << std::endl;;
	for (int i = 0; i < dynamicArray.getSize(); i++)
	{
		std::cout << i << ": " << array[i] << std::endl;
	}


	std::cout << "Size: " << dynamicArray.getSize() << std::endl;
	std::cout << "Capacity: " << dynamicArray.getCapacity() << std::endl;




	std::cout << "===================================\n\n\n";
	dynamicArray.pushback(2230);
	dynamicArray.pushback(123);
	dynamicArray.pushback(325);

	std::cout << "After adding more data: \n\n";

	std::cout << "Array: " << std::endl;;
	for (int i = 0; i < dynamicArray.getSize(); i++)
	{
		std::cout << i << ": " << array[i] << std::endl;
	}

	std::cout << "Size: " << dynamicArray.getSize() << std::endl;
	std::cout << "Capacity: " << dynamicArray.getCapacity() << std::endl;

	return 0;
}
