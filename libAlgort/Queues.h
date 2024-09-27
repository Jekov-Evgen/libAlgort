#pragma once


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
		T popLeft();
		void addToTheEnd(T);
		void clear();
	};

	template<typename T>
	class TwoWayQueue {
	private:
		template<typename T>
		class Node {
		public:
			T data;
			Node* nextElement;

			Node(T data = T(), Node nextElement = nullptr) {
				this->data = data;
				this->nextElement = nextElement;
			}
		};

		int size;
		Node<T>* head;

	public:
		TwoWayQueue();
		~TwoWayQueue();

		T popLeft();
		T popRight();
		int getSize();
		void clearElement();
		void clear();
	};
}