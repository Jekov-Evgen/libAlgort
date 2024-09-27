#pragma once
#include <stdexcept>

namespace DynArr 
{
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
        int capacity;
    };
}

namespace dy = DynArr;