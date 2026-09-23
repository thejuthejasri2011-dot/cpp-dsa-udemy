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


void removeduplicates() {
    Node* current = head;
    while(current != nullptr) {
        Node* runner = current;
        while(runner->next != nullptr) {
            if(runner->next->value == current->value) {
                Node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
                length--;
            }
            runner = runner->next;
        }
        current = current->next;
    }
}
};


int main() {
    Linkedlist* myLinkedlist = new Linkedlist(8);
    myLinkedlist->append(20);
    myLinkedlist->append(10);
    myLinkedlist->printlist();
    myLinkedlist->removeduplicates();
    myLinkedlist->printlist();

}
