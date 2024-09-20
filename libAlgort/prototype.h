#pragma once

namespace data_lists
{
	template<typename T>
	class SinglyLinkedList {
	private:
		template<typename T>
		class Node {
		public:
			T data;
			Node* nextElement;

			Node(T data = T(), Node* nextElement = nullptr) {
				this->data = data;
				this->nextElement = nextElement;
			}
		};

		int size;
		Node<T>* head;
	public:
		SinglyLinkedList();
		~SinglyLinkedList();
		T& operator[](const int index);

		void addToTheEnd(T);
		int getSizeList();
		void popFront();
		void clearList();
		void addToTheBeginning(T);
		void removingFromTheEnd();
		void insert(T, int);
		void removalFromTheMiddle(int);
	};
}

namespace queue_structures
{
	template<typename T>
	class Queue {
	private:
		template<typename T>
		class Node {
		public:
			T data;
			Node* nextElement;
			Node(T data = T(), Node* nextElement = nullptr) {
				this->data = data;
				this->nextElement = nextElement;
			}
		};

		int size;
		Node<T>* head;
	public:
		Queue();
		~Queue();

		int getSizeQueue();
		void popLeft();
		void addToTheEnd(T);
		void clear();
	};
}

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
