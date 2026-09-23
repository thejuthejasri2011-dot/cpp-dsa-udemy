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


int binaryToDecimal() {
    Node* current = head;
    int num=0;
    while(current != nullptr) {
        num = num*2 + current->value;
        current = current->next;
    }
    return num;
}
};


int main() {
    Linkedlist* myLinkedlist = new Linkedlist(1);
    myLinkedlist->append(0);
    myLinkedlist->append(1);
    myLinkedlist->printlist();
    cout << "Binary to Decimal: " << myLinkedlist->binaryToDecimal() << endl;

}
