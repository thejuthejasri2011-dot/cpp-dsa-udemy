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

class queue {
    private:
    Node* first;
    Node* last;
    int length;

    public:
    queue(int value){
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length =1;
    }

void printqueue(){
    Node* temp = first;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void enqueue(int value){
    Node* newNode = new Node(value);
    if(length==0){
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    length++;

} 


};

int main(){
    queue* myqueue = new queue(8);

    myqueue->enqueue(7);
 

    myqueue->printqueue();
}