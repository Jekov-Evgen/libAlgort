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

namespace dl = data_lists;