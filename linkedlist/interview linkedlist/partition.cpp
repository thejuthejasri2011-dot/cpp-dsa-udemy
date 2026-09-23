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


void partition(int x) {
    Node* dummy1 = new Node(0);
    Node* dummy2 = new Node(0);
    Node* prev1 = dummy1;
    Node* prev2 = dummy2;
    Node* current = head;
    while(current != nullptr) {
        if(current->value < x) {
            prev1->next = current;
            prev1 = current;
        } else {
            prev2->next = current;
            prev2 = current;
        }
        current = current->next;
    }
    prev2->next = nullptr;
    prev1->next = dummy2->next;
    head = dummy1->next;
    delete dummy1;
    delete dummy2;
}
};


int main() {
    Linkedlist* myLinkedlist = new Linkedlist(8);
    myLinkedlist->append(20);
    myLinkedlist->append(10);
        myLinkedlist->append(60);
    myLinkedlist->append(90);

    

    myLinkedlist->partition(25);
    myLinkedlist->printlist();

}
