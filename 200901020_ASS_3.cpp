#include <iostream>
#include <algorithm>
#include <thread>

// Function to merge two sorted arrays into a single sorted array
void merge(int* left, int leftSize, int* right, int rightSize, int* result)
{
    int i = 0, j = 0, k = 0;

    // Merge the two halves until one of them is exhausted
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            result[k] = left[i];
            i++;
        }
        else
        {
            result[k] = right[j];
            j++;
        }
        k++;
    }

    // Merge the remaining elements of the left half, if any
    while (i < leftSize)
    {
        result[k] = left[i];
        i++;
        k++;
    }

    // Merge the remaining elements of the right half, if any
    while (j < rightSize)
    {
        result[k] = right[j];
        j++;
        k++;
    }
}

// Recursive function to sort an array using merge sort algorithm
void mergeSort(int* arr, int size)
{
    // Base case: array of size 1 is already sorted
    if (size <= 1)
        return;

    // Split the array in half
    int mid = size / 2;
    int* left = arr;
    int leftSize = mid;
    int* right = arr + mid;
    int rightSize = size - mid;

    // Recursively sort the two halves
    mergeSort(left, leftSize);
    mergeSort(right, rightSize);

    // Allocate a temporary array to hold the merged result
    int* result = new int[size];

    // Merge the sorted halves
    merge(left, leftSize, right, rightSize, result);

    // Copy the merged result back to the original array
    std::copy(result, result + size, arr);

    // Free the temporary array
    delete[] result;
}

// Function to sort an array using multiple threads
void mergeSortMultithreaded(int* arr, int size)
{
    // Create two threads to sort the halves of the array
    std::thread t1([arr, size]() {
        int* left = arr;
        int leftSize = size / 2;
        mergeSort(left, leftSize);
    });

    std::thread t2([arr, size]() {
        int* right = arr + size / 2;
        int rightSize = size - size / 2;
        mergeSort(right, rightSize);
    });

    // Wait for the threads to finish
    t1.join();
    t2.join();

    // Allocate a temporary array to hold the merged result
    int* result = new int[size];

    // Merge the sorted halves
    merge(arr, size / 2, arr + size / 2, size - size / 2, result);
}

