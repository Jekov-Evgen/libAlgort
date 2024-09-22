#pragma once

namespace stack_area
{
	template <typename T>
	class Stack {
	private:
		int size;
		T* stackSpace;
	public:
		Stack();
		~Stack();

		void addingToTheStack(T);
		bool emptinessCheck();
		void removalFromTheTop();
		T vertexElement();
		int getSize();
	};
}

namespace stack_area
{
	template<typename T>
	inline Stack<T>::Stack()
	{
		size = 0;
		stackSpace = nullptr;
	}

	template<typename T>
	Stack<T>::~Stack()
	{
		delete[] stackSpace;
	}

	template<typename T>
	void Stack<T>::addingToTheStack(T data)
	{
		if (emptinessCheck() == true) {
			stackSpace = new T[1];
			stackSpace[0] = data;
			size = 1;
		}
		else {
			T* temporaryStorage = new T[size];

			for (int i = 0; i < size; i++)
			{
				temporaryStorage[i] = stackSpace[i];
			}

			delete[] stackSpace;

			stackSpace = new T[size + 1];

			for (int i = 0; i < size; i++)
			{
				stackSpace[i] = temporaryStorage[i];
			}

			stackSpace[size] = data;
			size++;

			delete[] temporaryStorage;
		}
	}

	template<typename T>
	bool Stack<T>::emptinessCheck()
	{
		return size == 0;
	}

	template<typename T>
	void Stack<T>::removalFromTheTop()
	{
		if (emptinessCheck() == true) {
			return;
		}
		else {
			T* temporaryStorage = new T[size - 1];

			for (int i = 0; i < size - 1; i++)
			{
				temporaryStorage[i] = stackSpace[i];
			}

			delete[] stackSpace;

			stackSpace = new T[size - 1];

			for (int i = 0; i < size - 1; i++)
			{
				stackSpace[i] = temporaryStorage[i];
			}

			delete[] temporaryStorage;
			size--;
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