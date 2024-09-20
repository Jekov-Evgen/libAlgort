#include <C:\Users\Женя\source\repos\libAlgort\libAlgort\prototype.h>

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
	void Queue<T>::popLeft() {
		if (head == nullptr) {
			throw std::out_of_range("Очередь пуста!");
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
			throw std::out_of_range("Очередь пуста!");  
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
			throw std::out_of_range("Очередь пуста!");
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
			return
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