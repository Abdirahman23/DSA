#include <iostream>
using namespace std;

class Node {

public:
	Node* prev;
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

class DoublyLinkedList {

private:
	Node* head;

public:

	DoublyLinkedList() {
		head = nullptr;
		
	}

	
	// Insertion at the start
	void insertAtStart(int data) {
		Node* newNode = new Node(data);

		if (head == nullptr) {
			head = newNode;
		}
		else {

			newNode->next = head;
			head->prev = newNode;

			head = newNode;
		}
	}


	// Insertion at the random position
	void insertAtRandomPosition(int data, int nodeData) {
		Node* current = head;
		while (current != nullptr && current->data != nodeData) {
			current = current->next;
		}

		if (current == nullptr) { // NodeData not found
			cout << "Node with data " << nodeData << " not found." << endl;
			return;
		}

		Node* newNode = new Node(data);
		newNode->next = current->next;
		if (current->next != nullptr) {
			current->next->prev = newNode;
		}
		current->next = newNode;
		newNode->prev = current;
	}

	void displayFromStart() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}



	// Insertion at the end
	void insertAtEnd(int data) {
		Node* newNode = new Node(data);

		if (head == nullptr) {
			head = newNode;
		}
		else {

			Node* temp = head;

			while (temp->next != nullptr)
				temp = temp->next;

			newNode->prev = temp;
			temp->next = newNode;

		}
	}

	//delete @ beginning

	void deleteAtBeginning() {
		if (head == nullptr) {
			cout << "List is empty, nothing to delete." << endl;
			return;
		}


		// if there is only one node(head)
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
		}
		//more than one node
		else {
			Node* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
		}
	}

	
	//delete @ end

	void deleteAtEnd() {
		if (head == nullptr) {
			cout << "List is empty, nothing to delete." << endl;
			return;
		}
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
		}
		// more than one node ; then delete @ end while looping towards the end
		else {
			Node* current = head;
			while (current->next->next != nullptr) {
				current = current->next;
			}
			Node* temp = current->next;
			
			current->next = nullptr;
			delete temp;
		}
	}


	//from start 2 end

	void displayFromStart() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}


	//end 2 start

	void displayFromEnd() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}

};

int main() {
	
	DoublyLinkedList Dlist;

	Dlist.insertAtStart(5);
	Dlist.insertAtStart(6);
	Dlist.insertAtStart(7);
	Dlist.insertAtStart(8);

	Dlist.insertAtRandomPosition(11,7);
	Dlist.insertAtEnd(9);

	Dlist.deleteAtEnd();

	Dlist.displayFromStart();

	cout << endl;

	Dlist.displayFromEnd();

	cout << endl;

	//delete @end
	Dlist.deleteAtEnd();

	Dlist.displayFromStart();

	cout << endl;
	//delete @start
	Dlist.deleteAtBeginning();

	Dlist.displayFromEnd();
     
	cout << endl;
	Dlist.displayFromEnd();

	cout << endl;

	return 0;
}



