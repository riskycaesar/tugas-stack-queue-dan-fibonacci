#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue kosong\n";
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;
}

void display() {
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);

    cout << "Isi Queue: ";
    display();

    dequeue();

    cout << "Setelah dequeue: ";
    display();
}