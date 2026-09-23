#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Linkedlist {
    private:
    Node* head;
    Node* tail;
    int length;

    public:
    Linkedlist(int value){
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
    Linkedlist* myLinkedlist = new Linkedlist(8);

    myLinkedlist->getHead();
    myLinkedlist->getTail();
    myLinkedlist->getlength();

    myLinkedlist->printlist();
}