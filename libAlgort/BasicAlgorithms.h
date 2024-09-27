#pragma once
#include <cstdlib>

namespace algorithms
{
	template<typename T>
	class Search {
	public:
		int linearSearch(T arr[], int size, T target);
		int binarySearch(T arr[], int size, T target);
	};

	template<typename T>
	class Sort {
	public:
		void insertionSort(T arr[], int size);
		void QuickSort(int arr[], int size);
	};
}
