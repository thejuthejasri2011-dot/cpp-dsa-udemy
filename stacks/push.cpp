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

class stack {
    private:
    Node* top;
    int height;

    public:
    stack(int value){
        Node* newNode = new Node(value);
        top = newNode;
        height =1;
    }

void printlist(){
    Node* temp = top;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
}
};



int main(){
    stack* mystack = new stack(8);

mystack->push(7);

    mystack->printlist();
}