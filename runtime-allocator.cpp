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
	int capacity;
	bool isRunning = true;
	
	
	
	std::cout << "Enter array capacity: ";
	std::cin >> capacity;

	DynamicArray dynamicArray(capacity);

	std::string input;
	int iInput;

	while (isRunning)
	{
		std::cout << "pushback/popback/print/q: ";
		std::cin >> input;

		if (input == "pushback")
		{
			std::cout << "number: ";
			std::cin >> iInput;

			dynamicArray.pushback(iInput);
		}
		else if (input == "popback")
		{
			dynamicArray.popback();
		}
		else if (input == "print")
		{
			int* arr = dynamicArray.getArray();

			std::cout << "\nArray:\n";

			for (int i = 0; i < dynamicArray.getSize(); i++)
			{
				std::cout << i << ": " << arr[i] << '\n';
			}

			std::cout << '\n';
		}
		else if (input == "q")
		{
			isRunning = false;
		}
		else
		{
			std::cout << "Invalid input.\n";
		}
	}
	

	


	return 0;
}
