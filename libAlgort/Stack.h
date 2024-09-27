#pragma once

namespace stack_area
{
	template <typename T>
	class Stack {
	private:
		int size;
		int currentCapacity;
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