#include "C:\Users\Æåíÿ\source\repos\libAlgort\libAlgort\SinglyLinkedList.h"

namespace data_lists
{
	template<typename T>
	SinglyLinkedList<T>::SinglyLinkedList() {
		size = 0;
		head = nullptr;
	}

	template<typename T>
	SinglyLinkedList<T>::~SinglyLinkedList() {
		clearList();
	}

	template<typename T>
	T& SinglyLinkedList<T>::operator[](const int index) {
		int count = 0;
		Node<T>* current = this->head;

		while (current != nullptr) {
			if (count == index) {
				return current->data;
			}
			current = current->nextElement;
			count++;
		}
	}

	template<typename T>
	void SinglyLinkedList<T>::addToTheEnd(T meaning) {
		if (head == nullptr) {
			head = new Node<T>(meaning);
		}
		else {
			Node<T>* current = this->head;

			while (current->nextElement != nullptr) {
				current = current->nextElement;
			}

			current->nextElement = new Node<T>(meaning);
		}

		size++;
	}

	template <typename T>
	int SinglyLinkedList<T>::getSizeList() {
		return size;
	}

	template <typename T>
	void SinglyLinkedList<T>::popFront() {
		Node<T>* temporaryStorage = head;

		head = head->nextElement;

		size--;

		delete temporaryStorage;
	}

	template <typename T>
	void SinglyLinkedList<T>::clearList() {
		while (size) {
			popFront();
		}
	}

	template<typename T>
	void SinglyLinkedList<T>::addToTheBeginning(T data) {
		head = new Node<T>(data, head);
		size++;
	}

	template<typename T>
	void SinglyLinkedList<T>::removingFromTheEnd() {
		removalFromTheMiddle(size - 1);
	}

	template<typename T>
	void SinglyLinkedList<T>::insert(T data, int index) {
		if (index == 0) {
			addToTheBeginning(data);
		}
		else {
			Node<T>* link = this->head;

			for (int i = 0; i < index - 1; i++) {
				link = link->nextElement;
			}

			link->nextElement = new Node<T>(data, link);

			size++;
		}
	}

	template<typename T>
	void SinglyLinkedList<T>::removalFromTheMiddle(int index) {
		if (index == 0) {
			popFront();
		}
		else {
			Node<T>* link = this->head;

			for (int i = 0; i < index - 1; i++) {
				link = link->nextElement;
			}

			Node<T> del = link->nextElement;
			link->nextElement = del.nextElement;

			delete del;
			size--;
		}
	}
}