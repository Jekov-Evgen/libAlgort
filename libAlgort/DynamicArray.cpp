#include "C:\Users\Женя\source\repos\libAlgort\libAlgort\DynamicArray.h"
#include <stdexcept>

namespace DynArr 
{
    template<typename T>
    inline DynamicArray<T>::DynamicArray(int cSize) {
        this->size = 0;
        this->capacity = (cSize > 0) ? cSize : 10;
        this->dynamicArr = new T[capacity];
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
        if (this->size < this->capacity) {
            this->dynamicArr[size] = value;
            size++;
        }
        else
        {
            capacity *= 2;
            T* tempStorage = new T[capacity];

            for (int i = 0; i < this->size; i++) {
                tempStorage[i] = this->dynamicArr[i];
            }

            delete[] this->dynamicArr;

            this->dynamicArr = tempStorage;

            dynamicArr[size] = value;
            size++;
        }
    }

    template<typename T>
    inline void DynamicArray<T>::pop_back() {
        if (this->size > 0) {
            this->size--;

            if (this->size < this->capacity / 2) {
                this->capacity /= 2;
                T* tempStorage = new T[this->capacity];

                for (int i = 0; i < this->size; ++i) {
                    tempStorage[i] = this->dynamicArr[i];
                }

                delete[] this->dynamicArr;

                this->dynamicArr = tempStorage;
            }
        }
        else
        {
            throw std::out_of_range("Невозможно удалить");
        }
    }

    template<typename T>
    inline int DynamicArray<T>::getSize() const {
        return this->size;
    }
}