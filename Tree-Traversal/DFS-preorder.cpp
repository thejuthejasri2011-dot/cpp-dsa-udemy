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

    void DFSPreorder(Node* currentNode){
        cout << currentNode->value << " ";
        if(currentNode->left){
            DFSPreorder(currentNode->left);
        }
        if(currentNode->right){
            DFSPreorder(currentNode->right);
        }
    }
    void DFSPreorder() {DFSPreorder(root);}
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

myBST->DFSPreorder();
}


