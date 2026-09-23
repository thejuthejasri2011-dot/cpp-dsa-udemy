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

void printstack(){
    Node* temp = top;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void getTop(){
    cout << "Top: " << top->value << endl;
}
void getheight(){
    cout << "Height:" << height << endl;
}
};

int main(){
    stack* mystack = new stack(8);

    mystack->getTop();
   
    mystack->getheight();

    mystack->printstack();
}