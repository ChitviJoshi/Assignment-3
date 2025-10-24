#include <iostream>
using namespace std;

const int MAX = 100;
int top = -1;

void push_made(int a[], int value) {
    if (top >= MAX - 1) {
        cout << "Stack overflow\n";
        return;
    }
    a[++top] = value;
}

void pop_made(int a[]) {
    if (top < 0) {
        cout << "Stack underflow\n";
        return;
    }
    top--;
}

int peek_made(int a[]) {
    if (top < 0) {
        cout << "Stack is empty\n";
        return -1;
    }
    return a[top];
}

bool isEmpty_made() {
    return top == -1;
}

bool isFull_made() {
    return top == MAX - 1;
}

void display_made(int arr[]) {
    if (top < 0) {
        cout << "Stack is empty\n";
    } else {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] <<endl;
        }
        cout << endl;
    }
}

int main() {
    int s[MAX];
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push_made(s, value);
                break;
            case 2:
                pop_made(s);
                break;
            case 3:
                cout << "Top element: " << peek_made(s) << endl;
                break;
            case 4:
                if (isEmpty_made()) {
                    cout << "Stack underflow" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 5:
                if (isFull_made()) {
                    cout << "Stack overflow" << endl;
                } else {
                    cout << "Stack is not full" << endl;
                }
                break;
            case 6:
                display_made(s);
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
