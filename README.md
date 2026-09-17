# Dynamic Array C++

This is a demo on dynamic array's in C++, built from scratch to understand how dynamically allocated memory, pointers, capacity management, and basic array operations work under the hood.

This project implements a custom `DynamicArray` class that can grow as it runs out of available capacity, it can also add or remove elements.

---

## Features
- `pushback(int i)` adds data to the array, data value is represented as `i`.
- `popback()` lowers the size off the array by 1; Essentially removing the last data
- `resize()` to double the capacity off the array.

---

## How it works

<img width="334" height="473" alt="image" src="https://github.com/user-attachments/assets/fd33b65e-8614-490f-bc70-655a2a5f2963" />

### Adding data

When we want to add data we have 2 goals:
- Add the data to the array at the first available slot
- Update the amount of data (`m_Size`) by the amount we stored, (1)

#### To achieve the first objective:

- `m_Arr[m_Size] = i;`
- We are adding data (i) to the next open data slot (m_Size)

#### As for the second objective:

- `m_Size++;`
- Is pretty self-explanatory

But wait, what if there isnt enough capacity to store more data:
#### Resizing
- For resizing the goal is to increase the array's capacity
- `m_Capacity *= 2;`
- Then we create a new array temporarily with the updated capacity:
- `int* newArr = new int[m_Capacity`
- We now want to add the data off the original array to the new one:
- ```
  for (int i = 0; i < m_Size; i++)	// Loop through the data of the original array
  {
  	newArr[i] = m_Arr[i];			// Transfer the data from original array to new array
  }
  ```
- Make the original array = new array
- `m_arr = newArr;`
---

### Removing data
- `m_Size--;`
- Removing data is as easy as subtracting `m_Size` by 1:
- `popback()` doesn't necessarily delete the data from the array, but it makes the index available in order for new data to be stored at the index instead.
