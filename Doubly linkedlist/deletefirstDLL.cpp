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


void deletefirst() {
    if(length == 0) return;
    Node* temp = head;
    if(length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    length--;
}
};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(8);

  
myDLL->append(7);
      myDLL->prepend(5);
      cout << "before deletefirst():" << endl;
      myDLL->printlist();

      myDLL->deletefirst();
      cout << "after deleteFirst():" << endl;

    myDLL->printlist();

}