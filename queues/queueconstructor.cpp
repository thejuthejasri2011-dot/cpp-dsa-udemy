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

void getFirst(){
    cout << "First: " << first->value << endl;
}
void getLast() {
        cout << "Last: " << last->value << endl;
}
void getlength(){
    cout << "Length:" << length << endl;
}
};

int main(){
    queue* myqueue = new queue(8);

    myqueue->getFirst();
   
    myqueue->getLast();
myqueue->getlength();

    myqueue->printqueue();
}