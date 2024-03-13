#include <iostream>

using namespace std;

class Stack {
private:
    int stack[10]; // Maximum stack size
    int top;       // Top index of the stack

public:
    Stack() {
        top = -1;
    }

    void push(int data) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
        }
        else {
            stack[++top] = data;
            cout << data << " pushed successfully." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        }
        else {
            top--;
        }
    }

    int topElement() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else {
            return stack[top]; // Return top element
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    int choice;  // Choice for stack operations
    int value;   // Value to push
    Stack s1;    // Declare Stack object outside the loop

    do {
        cout << "Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s1.push(value);
            break;

        case 2:
            value = s1.topElement(); // Get the top element before popping
            s1.pop();
            if (value != -1) {
                cout << "Popped element: " << value << endl;
            }
            break;

        case 3:
            value = s1.topElement();
            if (value != -1) {
                cout << "Top element: " << value << endl;
            }
            break;

        case 4:
            s1.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
