#pragma once

#include <iostream>

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	void push_back(T i);
	void pop_back();
	void resize();
	T* getArray() { return m_Arr; }
	int getSize() { return m_Size; }
	int getCapacity() { return m_Capacity; }

private:
	int m_Size;
	int m_Capacity;
	T* m_Arr;
};


// Constructor
template <typename T>
DynamicArray<T>::DynamicArray()
{
	m_Capacity = 10;				// Set capacity to the user's given capacity
	m_Size = 0;							// Initialize the size of array to 0; There is no data stored within yet
	m_Arr = new T[m_Capacity];		// Allocate m_Capacity amount of integers
}

template <typename T>
void DynamicArray<T>::push_back(T i)
{
	if (m_Size >= m_Capacity)			// Checks to see if the amount of data in array 
		// is greater than the capacity of the array
	{
		DynamicArray::resize();			// Call the resize function
	}
	m_Arr[m_Size] = i;					// Add the user data to the array at the next available memory slot
	m_Size++;							// Increase the amount of data so that the data cant be overwritten when not intended
}

template <typename T>
void DynamicArray<T>::pop_back()
{
	if (m_Size > 0) {
		m_Size--;							//  Make the amount of data 1 less; 
	}										// That allows future data to be added at the index of the current data
	else {
		m_Size += 10;
	}
}

template <typename T>
void DynamicArray<T>::resize()
{
	m_Capacity *= 2;					// Multply the data size by 2

	T* newArr = new T[m_Capacity];	// Make a new array

	for (int i = 0; i < m_Size; i++)	// Loop through the data of the original array
	{
		newArr[i] = m_Arr[i];			// Transfer the data from original array to new array
	}

	delete[] m_Arr;

	m_Arr = newArr;						// Set the original array's data equal to the new array; 
	// This allows the capacity to increase
}