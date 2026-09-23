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

bool isPalindrome(){
    Node* forwardNode = head;
    Node* backwardNode = tail;
    for(int i=0; i<length/2 ; i++){
        if(forwardNode->value != backwardNode->value){
            return false;
        }
        forwardNode = forwardNode->next;
        backwardNode = backwardNode->prev;
    } 
    return true;
}
};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(8);

  myDLL->append(2);
  cout << myDLL->isPalindrome() << endl;

    
}