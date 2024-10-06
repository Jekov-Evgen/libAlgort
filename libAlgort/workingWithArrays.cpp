#include "workingWithArrays.h"


template<typename T>
inline array_work::Arr<T>::Arr(T arr[], const int SIZE) {
	this->arr = new T[SIZE];
	this->size = SIZE;

	for (int i = 0; i < SIZE; i++) {
		this->arr[i] = arr[i];
	}
}

template<typename T>
T array_work::Arr<T>::searchForMinimum() {
	T min = this->arr[0];

	for (int i = 1; i < this->size; i++) {
		if (this->arr[i] < min) {
			min = this->arr[i];
		}
	}

	return min;
}

template<typename T>
T array_work::Arr<T>::searchForMaximum() {
	T max = arr[0];

	for (int i = 1; i < this->size; i++) {
		if (this->arr[i] > max) {
			max = this->arr[i];
		}
	}
}

template<typename T>
bool array_work::Arr<T>::sortingCheck(bool descendingAscending) {
	if (descendingAscending == true) {
		for (int i = 0; i < this->size - 1; i++) {
			if (this->arr[i] > this->arr[i + 1]) {
				return false;
			}
		}

		return true;
	}
	else {
		for (int i = 0; i < this->size - 1; i++) {
			if (this->arr[i] < this->arr[i + 1]) {
				return false;
			}
		}

		return true;
	}
}

template<typename T>
T array_work::Arr<T>::arithmeticMean() {
	T general;

	for (int i = 0; i < this->size; i++) {
		general += this->arr[i];
	}

	return general / this->size;
}

template<typename T>
T array_work::Arr<T>::findingTheSum() {
	T general;

	for (int i = 0; i < this->size; i++) {
		general += this->arr[i];
	}

	return general;
}

template<typename T>
void array_work::Arr<T>::removingDuplicates() {
	if (this->size == 0) return;

	T* temporaryStorage = new T[this->size];
	int newSize = 0;

	for (int i = 0; i < this->size; i++) {
		bool isDuplicate = false;

		for (int j = 0; j < newSize; j++) {
			if (this->arr[i] == temporaryStorage[j]) {
				isDuplicate = true;
				break;
			}
		}

		if (!isDuplicate) {
			temporaryStorage[newSize] = this->arr[i];
			newSize++;
		}
	}

	delete[] this->arr;
	this->arr = new T[newSize];
	this->size = newSize;

	for (int i = 0; i < newSize; i++) {
		this->arr[i] = temporaryStorage[i];
	}

	delete[] temporaryStorage;
}
