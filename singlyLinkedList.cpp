#include<iostream>
using namespace std;

//singly linked-list

class Node {

 public:
	 int data;
	 Node* next;

	 Node(int data) {
		 this->data = data;
		 this->next = nullptr;
	 }

};

class LinkedLists {

	Node* head;

public:

	LinkedLists() {
		head = nullptr;
	}

	// insertion from scratch

	void insert(int data) {

		Node* newNode = new Node(data);

		if (head == nullptr) {

			head = newNode;
		}
		else {
			Node* temp = head;

			while (temp->next != nullptr) {
				temp = temp->next;
			}

			temp->next = newNode;
		}
	}

	//insertion at the first point

	void insertAtHead(int data) {

		Node* newNode = new Node(data);
		newNode->next = head;

		head = newNode;

	}


	//deletion at the start

	void deleteAtTheStart() {

		Node* temp = head;

		if (head == nullptr)
			cout << "you can't delete head is empty!";


			head = head->next;

			delete temp;

	}

	//deletion at the random position

	void deleteAtRandomPosition(int position) {

		if (position < 0) {
			cout << "eror: wrong position to delete !";
			return;
		}

		if (position == 0) {

			if (head == nullptr)
				cout << "you can't delete head is empty!";

				//assign prev head pointer to temp
				Node* temp = head;

				head = head->next;

				delete temp;

				return;

		}

			// if position is not 0

			Node* current = head ;
			Node* previous = nullptr;

			//iterating prev & currnt till the destination postion
			int i = 0;

			while (i < position && current != nullptr) {
				previous = current;
				current = current->next;

				i++;
			}

			// jump over the current(the one to delete)

			previous->next = current->next;

			delete current;


		}



	void display() {

		if (head == nullptr) {
			cout << "head is empty !";
			return;
		}

		Node* temp = head;

		while (temp != nullptr) {
			cout << temp->data << " ";

			temp = temp->next;
		}


	}

};


int main() {


	LinkedLists list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(6);

	list.deleteAtTheStart();

	list.insertAtHead(5);

	list.deleteAtTheStart();

	list.deleteAtRandomPosition(2);

	list.display();

	return 0;
}



