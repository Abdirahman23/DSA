#include <iostream>
using namespace std;

class Node {

public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList {

private:
	Node* head;

public:

	LinkedList() {
		head = new Node(0); // Dummy node with data 0
		head->next = nullptr;
	}

	~LinkedList() {
		// Destructor to free allocated memory
		Node* current = head->next;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
		delete head;
	}

	// Insertion at the end
	void insert(int data) {
		Node* newNode = new Node(data);

		if (head->next == nullptr) {
			head->next = newNode;
		}
		else {
			Node* last = head->next;
			while (last->next != nullptr) {
				last = last->next;
			}
			last->next = newNode;
		}
	}

	// Insertion at a specific position (after the node with the given data)
	void insertAtRandomPosition(int data, int nodeData) {
		Node* current = head->next;
		while (current != nullptr && current->data != nodeData) {
			current = current->next;
		}

		if (current == nullptr) { // NodeData not found
			cout << "Node with data " << nodeData << " not found." << endl;
			return;
		}

		Node* newNode = new Node(data);
		newNode->next = current->next;
		current->next = newNode;
	}

	// Deletion at the beginning
	void deleteAtTheStart() {
		if (head->next == nullptr) { // List is empty
			cout << "List is empty, cannot delete." << endl;
			return;
		}

		Node* temp = head->next;
		head->next = temp->next;
		delete temp;
	}

	// Deletion at a specific position (after the node with the given data)
	void deleteAtRandomPosition(int nodeData) {
		if (head->next == nullptr) { // List is empty
			cout << "List is empty, cannot delete." << endl;
			return;
		}

		Node* current = head->next;
		Node* prev = head;

		while (current != nullptr && current->data != nodeData) {
			prev = current;
			current = current->next;
		}

		if (current == nullptr) { // NodeData not found
			cout << "Node with data " << nodeData << " not found." << endl;
			return;
		}

		prev->next = current->next;
		delete current;
	}

	void printList() {
		Node* current = head->next;
		while (current != nullptr) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "NULL" << endl;
	}
};

int main() {
	LinkedList list;

	list.insert(5);
	list.insert(3);
	list.insert(1);

	cout << "Linked list before deletions: ";
	list.printList();

	list.deleteAtTheStart();
	cout << "Linked list after deleting at start: ";
	list.printList();

	list.deleteAtRandomPosition(3);
	cout << "Linked list after deleting 3: ";
	list.printList();

	list.insertAtRandomPosition(7, 5);
	cout << "Linked list after inserting 7 after 5: ";
	list.printList();

	return 0;
}



