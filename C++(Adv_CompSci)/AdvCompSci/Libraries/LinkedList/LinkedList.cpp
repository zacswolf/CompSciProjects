#include <iostream>
#include <stdexcept>



class LinkedList {
	friend class LLIterator;
	class Node {
	friend class LLIterator;
	public:
		int value;
		void setNext(Node* n) {
			next = n;
		}
		void setPrev(Node* n) {
			prev = n;
		}
		Node* next;
		Node* prev;
	};
	
public:
	LinkedList() { // Initial empty list conditions
		head = NULL;
		tail = NULL;
		length = 0;
	}
	~LinkedList() { // Removes each Node
		while (head != NULL && tail != NULL) pop(); // Pop each value to clear memory
	}

	unsigned int size() { // Returns the size of the list
		return length;
	}

	int &operator[](unsigned int index) { // Returns the value at the given index
		Node* node = head;
		for (int i = 0; i < index; ++i) {
			node = node->next;
			if (node == NULL) {
				std::string error("Offset of out of range");
				throw std::range_error(std::string(error));
			}
		}
		return node->value;
	}

	void add(int val) { // Adds a value to the beginning of the list
		Node* newNode = new Node();
		newNode->value = val;
		if (head != NULL) {
			head->setPrev(newNode);
		}
		newNode->next = head;
		newNode->prev =	NULL;
		head = newNode;
		if (length == 0) {
			tail = newNode;
		}

		length++;
	}
	void push(int val) { // Pushes a value to the end of the list
		Node* newNode = new Node();
		newNode->value = val;
		if (tail != NULL) {
			tail->setNext(newNode);
		}
		newNode->prev = tail;
		newNode->next =	NULL;
		tail = newNode;
		if (length == 0) {
			head = newNode;
		}

		length++;
	}
	void insert(int index, int val) { // Inserts a value at index in the list
		if (index == length-1) {
			this->push(val);
			return;
		}
		Node* newNode = new Node();
		newNode->value = val;
		Node* before = this->nodeAt(index);
		Node* after = before->next;

		newNode->next = after;
		newNode->prev = before;
		before->next = newNode;
		after->prev = newNode;
		length++;
	}

	int pop() { // Pops a value from the beginning and returns it
		if (head == NULL || tail == NULL) {
			std::string error("Cannot pop empty list");
			throw std::range_error(error);
		}
		Node* n = head;
		int ret = n->value;
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
		delete n;

		length--;
		return ret;
	}
	int shift() { // Shifts a value from the end and returns it
		if (head == NULL || tail == NULL) {
			std::string error("Cannot shift empty list");
			throw std::range_error(error);
		}
		Node* n = tail;
		int ret = n->value;
		tail = tail->prev;
		if (tail != NULL) {
			tail->next = NULL;
		}
		delete n;

		length--;
		return ret;
	}
	int remove(int index) {
		if (index == 0) {
			return this->pop();
		}
		if (index == length-1) {
			return this->shift();
		}
		Node* n = this->nodeAt(index);
		int ret = n->value;
		Node* before = n->prev;
		Node* after = n->next;
		before->next = after;
		after->prev = before;
		delete n;

		length--;
		return ret;
	}
	
	
	

private:
	Node* nodeAt(int index) {
		Node* node = head;
		for (int i = 0; i < index; ++i) {
			node = node->next;
			if (node == NULL) {
				std::string error("Offset of out of range");
				throw 1;
			}
		}
		return node;
	}

	Node* head;
	Node* tail;
	int length;
};

class LLIterator{
	friend class LinkedList;
	friend class LinkedList::Node;
	LinkedList* myList;
	public:
	LLIterator(LinkedList* L){
		myList=L;
	}
	LinkedList::Node* myNode;
	void begin(){
		myNode = myList->head;
	}
	void operator++(){
		myNode = myNode->next;
	}
	void operator--(){
		myNode = myNode->prev;
	}
	int operator*(){
		return myNode->value;
	}
};

int main() {
	LinkedList list;

	list.add(100); // list = [100]
	list.add(12); // list = [12, 100]
	list.push(15); // list = [12, 100, 15]
	list.insert(2,32); // list = [12, 100, 15, 32]
	list.remove(1); // list = [12, 15, 32]
	
	LLIterator iter(&list) ;
	iter.begin();
	std::cout << *iter << std::endl;
	++iter;
	std::cout << *iter << std::endl;
	++iter;
	std::cout << *iter << std::endl;
	--iter;
	--iter;
	std::cout << *iter << std::endl;

	/*while (list.size()) {
		std::cout << list.pop() << std::endl; // prints elements one by one
	}*/
	

	return 0;
}
