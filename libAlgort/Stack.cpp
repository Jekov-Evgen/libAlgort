#include <C:\Users\Æåíÿ\source\repos\libAlgort\libAlgort\Stack.h>
#include <algorithm>

namespace stack_area
{
	template<typename T>
	inline Stack<T>::Stack() {
		size = 0;
		currentCapacity = 1;
		stackSpace = new T[currentCapacity];
	}

	template<typename T>
	Stack<T>::~Stack() {
		delete[] stackSpace;
	}

	template<typename T>
	void Stack<T>::addingToTheStack(T data) {
		if (emptinessCheck() == true) {
			stackSpace = new T[1];
			stackSpace[0] = data;
			currentCapacity = 1;
		}
		else {
			if (size == currentCapacity) {
				currentCapacity = currentCapacity + (currentCapacity / 2);
				T* temporaryStorage = new T[currentCapacity];

				for (int i = 0; i < size; i++) {
					temporaryStorage[i] = stackSpace[i];
				}

				delete[] stackSpace;
				stackSpace = temporaryStorage;
			}

			stackSpace[size] = data;
		}

		size++;
	}

	template<typename T>
	bool Stack<T>::emptinessCheck() {
		return size == 0;
	}

	template<typename T>
	void Stack<T>::removalFromTheTop() {
		if (emptinessCheck()) {
			return;
		}

		size--;

		if (size < currentCapacity / 4 && currentCapacity > 1) {
			currentCapacity = std::max(1, currentCapacity / 2);
			T* temporaryStorage = new T[currentCapacity];

			for (int i = 0; i < size; i++) {
				temporaryStorage[i] = stackSpace[i];
			}

			delete[] stackSpace;
			stackSpace = temporaryStorage;
		}
	}

	template<typename T>
	T Stack<T>::vertexElement()
	{
		return stackSpace[size - 1];
	}

	template<typename T>
	int Stack<T>::getSize()
	{
		return size;
	}
}

namespace sa = stack_area;