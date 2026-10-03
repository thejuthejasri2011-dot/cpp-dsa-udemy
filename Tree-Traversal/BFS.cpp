#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

};

class BinarySearchTree{
    public:
    Node*root;

    public:
    BinarySearchTree(){
        root = nullptr;
    }

    bool insert(int value){
        Node* newNode = new Node(value);
        if(root == nullptr){
            root = newNode;
            return true;
        }
        Node* temp = root;
        while(true) {
            if(newNode->value == temp->value) return false;
            if(newNode->value < temp->value){
                if(temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            } else {
                if(temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

      bool contains(int value) {
        if(root == nullptr) return false;
        Node* temp = root;
        while(temp) {
            if(value < temp->value){
                temp = temp->left;
            } else if(value > temp->value) {
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;
    }

    void BFS(){
        queue<Node*> myQueue;
        myQueue.push(root);
        while(myQueue.size()>0){
            Node* currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";
            if(currentNode->left != nullptr){
                myQueue.push(currentNode->left);
            }
            if(currentNode->right != nullptr){
                myQueue.push(currentNode->right);
            }
        }

    }


};

int main() {
BinarySearchTree* myBST = new BinarySearchTree();
myBST->insert(47);
myBST->insert(21);
myBST->insert(76);
myBST->insert(81);
myBST->insert(52);
myBST->insert(82);
myBST->insert(27);

myBST->BFS();

}