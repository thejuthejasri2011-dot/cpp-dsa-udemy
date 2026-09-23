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

void deletefirst() {
    if(length == 0) return;
    Node* temp = head;
    if(length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    length--;
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

void deletelast() {
    if(length==0) return;
    Node* temp = head;
    if(length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}


void prepend(int value) {
    Node* newNode = new Node(value);
    if(length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}


Node* get(int index) {
    if(index<0 || index>=length) return nullptr;
    Node*temp;
    if(index<length/2) {
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
    } else {
        temp = tail;
        for(int i=length-1; i>index; i--) {
            temp = temp->prev;
        }
    }
    return temp;
}


bool set(int index, int value) {
    Node* temp = get(index);
    if(temp){
        temp->value = value;
        return true;
    }
    return false;
}


bool insert(int index, int value) {
    if(index < 0 || index > length) return false;
    if(index == 0) {
        prepend(value);
        return true;
    }
    if(index == length) {
        append(value);
        return true;
    }
    Node* newNode = new Node(value);
    Node* after = get(index);
    Node* before = after->prev;
    newNode->next = after;
    newNode->prev = before;
    before->next = newNode;
    after->prev = newNode;
    length++;
    return true;
}


void deleteNode(int index) {
    if(index<0 || index>=length) return;
    if(index == 0) return deletefirst();
    if(index==length-1) return deletelast();
    Node* temp = get(index);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    length--;
}
};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(8);
myDLL->prepend(5);
    cout << myDLL->get(1)->value << endl;
    myDLL->set(1, 10);
    myDLL->insert(2, 15);
    myDLL->deleteNode(1);
myDLL->printlist();
}