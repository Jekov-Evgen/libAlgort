#pragma once
#include <stdexcept>

template <typename T>
class SmartPtr {
public:
	SmartPtr(int);
	SmartPtr(const SmartPtr&);
	SmartPtr(SmartPtr&& other) noexcept;
	SmartPtr& operator=(SmartPtr&& other) noexcept;
	~SmartPtr();

	T& operator[](int);
	SmartPtr& operator=(const SmartPtr&);
	T* operator->();
	T& operator*();
	operator bool() const;
	bool operator==(const SmartPtr&);
	bool operator!=(const SmartPtr&);
	int GetSize();
	void reset(int);
private:
	T* sPtr;
	int size;
};

template<typename T>
inline SmartPtr<T>::SmartPtr(int size)
{
	this->size = size;

	this->sPtr = new T[size];
}

template<typename T>
inline SmartPtr<T>::~SmartPtr() {
	delete[] this->sPtr;
}

template<typename T>
inline T& SmartPtr<T>::operator[](int index) {
	if (index >= size || index < 0) {
		throw std::out_of_range("going abroad");
	}

	return sPtr[index];
}

template<typename T>
inline SmartPtr<T>::SmartPtr(const SmartPtr& other) {
	if (this->size != 0) {
		delete[] this->sPtr;
	}

	this->size = other.size;
	this->sPtr = new T[size];

	for (int i = 0; i < this->size; i++) {
		this->sPtr[i] = other.sPtr[i];
	}
}

template<typename T>
inline SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr& other) {
	if (this != &other) {
		delete[] this->sPtr;
		this->size = other.size;
		this->sPtr = new T[size];

		for (int i = 0; i < this->size; i++) {
			sPtr[i] = other.sPtr[i];
		}
	}

	return *this;
}

template<typename T>
inline int SmartPtr<T>::GetSize() {
	return this->size;
}

template<typename T>
inline SmartPtr<T>::SmartPtr(SmartPtr&& other) noexcept {
	this->size = other.size;
	this->sPtr = other.sPtr;

	other.size = 0;
	other.sPtr = nullptr;
}

template<typename T>
inline SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr&& other) noexcept {
	if (this != &other) {
		delete[] this->sPtr;
		this->size = other.size;
		this->sPtr = other.sPtr;

		other.size = 0;
		other.sPtr = nullptr;
	}

	return *this;
}

template<typename T>
inline T* SmartPtr<T>::operator->() {
	return sPtr;
}

template<typename T>
inline T& SmartPtr<T>::operator*() {
	return *sPtr;
}

template<typename T>
inline void SmartPtr<T>::reset(int newSize) {
	delete[] this->sPtr;
	this->size = newSize;
	this->sPtr = new T[size];
}

template<typename T>
inline bool SmartPtr<T>::operator==(const SmartPtr& other) {
	if (this->size == other.size) {
		for (int i = 0; i < this->size; i++) {
			if (other.sPtr[i] != this->sPtr[i]) {
				return false;
			}
		}

		return true;
	}
	
	return false;
}

template<typename T>
inline bool SmartPtr<T>::operator!=(const SmartPtr& other)
{
	if (other.size != this->size) {
		return true;
	}
	else
	{
		for (int i = 0; i < this->size; i++) {
			if (this->sPtr[i] == other.sPtr[i]) {
				return false;
			}
		}

		return true;
	}
}

template<typename T>
inline SmartPtr<T>::operator bool() const {
	return this->sPtr != nullptr;
}
