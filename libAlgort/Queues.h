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


namespace queue_structures {
	template<typename T>
	Queue<T>::Queue()
	{
		size = 0;
		head = nullptr;
	}

	template<typename T>
	Queue<T>::~Queue()
	{
		clear();
	}

	template<typename T>
	inline int Queue<T>::getSizeQueue() {
		return size;
	}

	template<typename T>
	T Queue<T>::popLeft() {
		if (head == nullptr) {
			throw ("За пределы");
		}

		Node<T>* temp = head;
		T data = temp->data;
		head = head->nextElement;

		size--;
		delete temp;

		return data;
	}

	template<typename T>
	void Queue<T>::addToTheEnd(T data) {
		if (head == nullptr) {
			head = new Node<T>(data);
		}
		else {
			Node<T>* current = this->head;

			while (current->nextElement != nullptr) {
				current = current->nextElement;
			}
			current->nextElement = new Node<T>(data);
			size++;
		}
	}

	template<typename T>
	void Queue<T>::clear()
	{
		while (size) {
			popLeft();
		}
	}

	template<typename T>
	queue_structures::TwoWayQueue<T>::TwoWayQueue() {
		size = 0;
		head = nullptr;
	}

	template<typename T>
	queue_structures::TwoWayQueue<T>::~TwoWayQueue() {
		clear();
	}

	template<typename T>
	inline T queue_structures::TwoWayQueue<T>::popLeft() {
		if (head == nullptr) {
			throw ("За пределы");
		}

		Node<T>* temp = head;
		T data = temp->data;
		head = head->nextElement;

		size--;
		delete temp;

		return data;
	}

	template<typename T>
	T queue_structures::TwoWayQueue<T>::popRight() {
		if (head == nullptr) {
			throw ("За пределы");
		}

		if (head->nextElement == nullptr) {
			T data = head->data;
			delete head;
			head = nullptr;
			size--;
			return data;
		}

		Node<T>* current = head;

		while (current->nextElement->nextElement != nullptr) {
			current = current->nextElement;
		}

		T data = current->nextElement->data;

		delete current->nextElement;

		current->nextElement = nullptr;

		size--;

		return data;
	}

	template<typename T>
	int queue_structures::TwoWayQueue<T>::getSize() {
		return size;
	}

	template<typename T>
	void queue_structures::TwoWayQueue<T>::clearElement() {
		if (head == nullptr) {
			return;
		}

		Node<T>* temporaryStorage = head;

		head = head->nextElement;

		size--;

		delete temporaryStorage;
	}

	template<typename T>
	void TwoWayQueue<T>::clear()
	{
		while (size) {
			clearElement();
		}

		head = nullptr;
	}
}

namespace qs = queue_structures;