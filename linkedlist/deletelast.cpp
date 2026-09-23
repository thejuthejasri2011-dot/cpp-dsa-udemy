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
void append(int value) {
    Node* newNode = new Node(value);
    if(length==0) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}


void deletelast() {
    if(length==0) return;
    Node* temp = head;
    Node* pre = head;
    while(temp->next) {
        pre = temp;
        temp = temp->next;
    }
    tail = pre;
    tail->next = nullptr;
    length--;
    if(length==0) {
        head = nullptr;
        tail = nullptr;
    }
    delete temp;
}
};

int main() {
    Linkedlist* myLinkedlist = new Linkedlist(8);
    myLinkedlist->append(20);
    myLinkedlist->append(10);
    cout << "LL before delete of last(): \n" << endl;
    myLinkedlist->printlist();
    myLinkedlist->deletelast();
    cout << "LL after delete of last1(): \n" << endl;
        myLinkedlist->printlist();
        myLinkedlist->deletelast();
        cout << "LL after delete of last1(): \n" << endl;
                myLinkedlist->printlist();
        myLinkedlist->deletelast();
        cout << "LL after delete of last1(): \n" << endl;
                myLinkedlist->printlist();




}
