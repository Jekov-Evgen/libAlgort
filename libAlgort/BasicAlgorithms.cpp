#include <C:\Users\Æåíÿ\source\repos\libAlgort\libAlgort\BasicAlgorithms.h>

namespace algorithms
{
	template<typename T>
	int Search<T>::linearSearch(T arr[], int size, T target) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == target) {
				return i;
			}
		}
		return -1;
	}

	template<typename T>
	int Search<T>::binarySearch(T arr[], int size, T target) {
		int left = 0;
		int right = size - 1;

		while (left <= right) {
			int middle = left + (right - left) / 2;

			if (arr[middle] == target) {
				return middle;
			}

			if (arr[middle] < target) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}

		return -1;
	}

	template<typename T>
	void Sort<T>::insertionSort(T arr[], int size) {
		for (int i = 1; i < size; i++) {
			T key = arr[i];
			int j = i - 1;

			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}

	template<typename T>
	inline void algorithms::Sort<T>::QuickSort(int arr[], int size) {
		if (size < 2) {
			return;
		}
		else {
			int SupportElement = rand() % size;
			int pivont = arr[SupportElement];
			int sizeLarger = 0, sizeSmaller = 0, equalSize = 0;

			for (int i = 0; i < size; i++) {
				if (pivont > arr[i]) {
					sizeSmaller++;
				}
				else if (pivont < arr[i]) {
					sizeLarger++;
				}
				else {
					equalSize++;
				}
			}

			int* arrayForLarge = new int[sizeLarger];
			int* arrayForSmallerOnes = new int[sizeSmaller];

			int idxSmaller = 0, idxLarger = 0, idx = 0;

			for (int i = 0; i < size; i++) {
				if (arr[i] < pivont) {
					arrayForSmallerOnes[idxSmaller++] = arr[i];
				}
				else if (arr[i] > pivont) {
					arrayForLarge[idxLarger++] = arr[i];
				}
			}

			QuickSort(arrayForSmallerOnes, sizeSmaller);
			QuickSort(arrayForLarge, sizeLarger);

			for (int i = 0; i < sizeSmaller; i++) {
				arr[idx++] = arrayForSmallerOnes[i];
			}
			for (int i = 0; i < equalSize; i++) {
				arr[idx++] = pivont;
			}
			for (int i = 0; i < sizeLarger; i++) {
				arr[idx++] = arrayForLarge[i];
			}

			delete[] arrayForSmallerOnes;
			delete[] arrayForLarge;
		}
	}
}

namespace al = algorithms;