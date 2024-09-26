#pragma once
#include <stdexcept>

template <typename T>
class DynamicArray {
public:
    DynamicArray(int);
    ~DynamicArray();

    T& operator[](int index);
    void push_back(const T& value);
    void pop_back();
    int getSize() const;
private:
	T* dynamicArr;
	int size;

};

template<typename T>
inline DynamicArray<T>::DynamicArray(int createSize) {
    if (createSize > 0) {
        this->size = createSize;
        this->dynamicArr = new T[size];
    }

    for (int i = 0; i < this->size; i++) {
        this->dynamicArr[i] = T();
    }
}

template<typename T>
inline DynamicArray<T>::~DynamicArray() {
    delete[] this->dynamicArr;
}

template<typename T>
inline T& DynamicArray<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        return dynamicArr[index];
    }

    throw std::out_of_range("Индекс выходит за границы массива");

}

template<typename T>
inline void DynamicArray<T>::push_back(const T& value) {
    bool emptiness = false;

    for (int i = 0; i < this->size; i++) {
        if (this->dynamicArr[i] == T()) {
            this->dynamicArr[i] = value;

            emptiness = true;
            break;
        }
    }

    if (emptiness == false) {
        T* temporaryStorage = new T[size];

        for (int i = 0; i < this->size; i++) {
            temporaryStorage[i] = this->dynamicArr[i];
        }

        delete[] this->dynamicArr;

        this->dynamicArr = new T[size + 1];

        for (int i = 0; i < this->size; i++) {
            this->dynamicArr[i] = temporaryStorage[i];
        }

        dynamicArr[size] = value;
        delete[] temporaryStorage;

        this->size++;
    }
}

template<typename T>
inline void DynamicArray<T>::pop_back() {
    T* temporaryStorage = new T[size - 1];

    for (int i = 0; i < this->size - 1; i++) {
        temporaryStorage[i] = this->dynamicArr[i];
    }

    delete[] dynamicArr;

    this->dynamicArr = new T[size - 1];

    for (int i = 0; i < this->size - 1; i++) {
        this->dynamicArr[i] = temporaryStorage[i];
    }
    
    delete[] temporaryStorage;

    this->size--;
}

template<typename T>
inline int DynamicArray<T>::getSize() const {
    return this->size;
}