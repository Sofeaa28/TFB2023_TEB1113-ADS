#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next_ptr;
};

struct Stack {
    Node* top; // pointer to the top of the stack
};

// Initialize stack
void initialize(Stack &s) {
    s.top = nullptr;
}

// Check if stack is empty
bool isEmpty(Stack s) {
    return (s.top == nullptr);
}

// Check if stack is full (simulate memory limit)
bool isFull() {
    Node* temp = new(nothrow) Node;
    if (temp == nullptr)
        return true;
    delete temp;
    return false;
}

// Push operation
void push(Stack &s, string value) {
    if (isFull()) {
        cout << "Stack overflow! Cannot push " << value << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next_ptr = s.top;
    s.top = newNode;

    cout << value << " pushed onto stack." << endl;
}

// Pop operation
void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack underflow! Cannot pop." << endl;
        return;
    }

    Node* temp = s.top;
    cout << s.top->data << " popped from stack." << endl;
    s.top = s.top->next_ptr;
    delete temp;
}

// Peek operation
void peek(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack is empty. Nothing to peek." << endl;
        return;
    }
    cout << "Top element: " << s.top->data << endl;
}

// Display operation
void display(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack contents (top to bottom): ";
    Node* current = s.top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next_ptr;
    }
    cout << endl;
}

// Main function with user input
int main() {
    Stack s;
    initialize(s);

    int choice;
    string value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                display(s);
                break;
            case 5:
                if (isEmpty(s))
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 6:
                if (isFull())
                    cout << "Stack is full (no more memory available)." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
