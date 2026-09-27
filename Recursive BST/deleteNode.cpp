#include <iostream>

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


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 
        
        Node* rInsert(Node* currentNode, int value) {
            if (currentNode == nullptr) return new Node(value);
        
            if (value < currentNode->value) {
                currentNode->left = rInsert(currentNode->left, value);
            } else if (value > currentNode->value) {
                currentNode->right = rInsert(currentNode->right, value);
            } 
            return currentNode;
        }
        void rInsert(int value) { 
            if (root == nullptr) root = new Node(value);
            rInsert(root, value); 
        } 
        
        bool rContains(Node* currentNode, int value) {
            if (currentNode == nullptr) return false;
            
            if (currentNode->value == value) return true;
            
            if (value < currentNode->value) {
                return rContains(currentNode->left, value);
            } else {
                return rContains(currentNode->right, value);
            }
        }
        bool rContains(int value) { 
            return rContains(root, value); 
        } 

        int minValue(Node* currentNode) {
            while (currentNode->left != nullptr) {
                currentNode = currentNode->left;
            }
            return currentNode->value;
        } 
              
        Node* deleteNode(Node*currentNode,int value){
            if(currentNode == nullptr) return nullptr;
            if(value < currentNode->value){
                currentNode->left = deleteNode(currentNode->left,value);
            } else if(value > currentNode->value){
                currentNode->right = deleteNode(currentNode->right,value);
            } else {
                if(currentNode->left == nullptr && currentNode->right == nullptr){
                    delete(currentNode);
                    return nullptr;
                } else if(currentNode->left == nullptr){
                    Node* temp = currentNode->right;
                    delete(currentNode);
                    return temp;
                } else if(currentNode->right == nullptr){
                    Node* temp = currentNode->left;
                    delete(currentNode);
                    return temp;
                } else {
                    int subTreeMin = minValue(currentNode->right);
                    currentNode->value = subTreeMin;
                    currentNode->right = deleteNode(currentNode->right,subTreeMin);
                }
            }
            return currentNode;
        }

        void deleteNode(int value) { root = deleteNode(root, value); }

};

int main(){
     BinarySearchTree* myBST = new BinarySearchTree();
    myBST->rInsert(2);
    myBST->rInsert(1);
    myBST->rInsert(3);

    cout << "\nBefore Deleting(2) Node:\n";
    cout << "------------------------------";
    cout << "\nRoot: " << myBST->getRoot()->value;
    cout << "\n\nRoot->left:" << myBST->getRoot()->left->value;
    cout << "\n\nRoot->Right:" << myBST->getRoot()->right->value;

    myBST->deleteNode(2);
    cout << "\n\nAfter Deleting(2) Node:\n";
    cout << "-------------------------------";
     cout << "\nRoot: " << myBST->getRoot()->value << endl;
    cout << "\n\nRoot->left:" << myBST->getRoot()->left->value << endl;
    cout << "\n\nRoot->Right:" << myBST->getRoot()->right->value << endl;

}