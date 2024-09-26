#pragma once

template <typename T>
class SmartPtr {
public:
	SmartPtr(int);
	SmartPtr(const SmartPtr&);
	~SmartPtr();

	T& operator[](int);
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
inline SmartPtr<T>::~SmartPtr()
{
	delete[] sPtr;
}

template<typename T>
inline T& SmartPtr<T>::operator[](int index)
{
	if (index >= size || index < 0) {
		throw ("Такого элимента не существует");
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



