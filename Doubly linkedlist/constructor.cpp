#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node* prev;
    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    private:
    Node* head;
    Node* tail;
    int length;

    public:
    DoublyLinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length =1;
    }

void printlist(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void getHead(){
    cout << "Head: " << head->value << endl;
}
void getTail(){
    cout << "Tail: " << tail->value << endl;
}
void getlength(){
    cout << "Length:" << length << endl;
}
};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(8);

    myDLL->getHead();
    myDLL->getTail();
    myDLL->getlength();

    myDLL->printlist();
}