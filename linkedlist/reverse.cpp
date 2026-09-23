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

void deleteFirst(){
if(length==0) return;

Node* temp = head;

if(length==1) {
    head = nullptr;
    tail = nullptr;
} else {
    head = head->next;
}

delete temp;
length--;
}


Node* get(int index) {
    if(index<0 || index>=length) return nullptr;
    Node* temp = head;
    for(int i=0; i<index; i++) {
        temp = temp->next;
    }
    return temp;
    }

    void deletenode(int index) {
        if(index<0 || index>=length) return;
        if(index==0) return deleteFirst();
        if(index==length-1) return deletelast();
        Node* prev = get(index-1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* after = temp->next;
        Node* before = nullptr;
        for(int i=0; i<length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

};

int main() {
    Linkedlist* myLinkedlist = new Linkedlist(8);
    myLinkedlist->append(20);
    myLinkedlist->append(10);
    
    myLinkedlist->reverse();
    myLinkedlist->printlist();
}
      





