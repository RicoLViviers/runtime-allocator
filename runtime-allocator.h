#pragma once

#include <iostream>

class DynamicArray
{
public:
	DynamicArray(int capacity);
	void pushback(int i);
	void popback();
	void resize();
	int* getArray() { return m_Arr; }
	int getSize() { return m_Size; }
	int getCapacity() { return m_Capacity; }

private:
	int m_Size;
	int m_Capacity;
	int* m_Arr;
};