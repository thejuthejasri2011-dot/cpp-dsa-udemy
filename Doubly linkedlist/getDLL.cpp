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


void append(int value) {
    Node* newNode = new Node(value);
    if(length==0) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}


void prepend(int value) {
    Node* newNode = new Node(value);
    if(length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}


Node* get(int index) {
    if(index<0 || index>=length) return nullptr;
    Node*temp;
    if(index<length/2) {
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
    } else {
        temp = tail;
        for(int i=length-1; i>index; i--) {
            temp = temp->prev;
        }
    }
    return temp;
}
};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(8);
myDLL->prepend(5);
    cout << myDLL->get(1)->value << endl;

}