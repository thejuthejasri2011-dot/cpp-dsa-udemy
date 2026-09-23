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


void reverseBetween(int m, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    for(int i=0; i<m; i++) {
        prev = prev->next;
    }
    Node* current = prev->next;
    for(int i=0; i<n-m; i++) {
        Node* temp = current->next;
        current->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    head = dummy->next;
    delete dummy;
}

};


int main() {
    Linkedlist* myLinkedlist = new Linkedlist(8);
    myLinkedlist->append(20);
    myLinkedlist->append(10);
    myLinkedlist->reverseBetween(1,2);
    myLinkedlist->printlist();

}
