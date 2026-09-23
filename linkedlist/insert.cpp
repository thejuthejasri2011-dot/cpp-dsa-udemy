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

void prepend(int value) {
    Node* newNode = new Node(value);
    if(length==0) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    length++;
}


Node* get(int index) {
    if(index<0 || index>=length) return nullptr;
    Node* temp = head;
    for(int i=0; i<index; i++) {
        temp = temp->next;
    }
    return temp;
    }


bool insert(int index, int value) {
    if(index<0 || index>length) return false;
    if(index==0) {
        prepend(value);
        return true;
    }
    if(index==length) {
        append(value);
        return true;
    }
    Node* newNode = new Node(value);
    Node*temp = get(index-1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
}
};


int main() {
    Linkedlist* myLinkedlist = new Linkedlist(8);
    myLinkedlist->append(20);
    myLinkedlist->append(10);
    myLinkedlist->insert(2,88);
    myLinkedlist->printlist();

    
}
