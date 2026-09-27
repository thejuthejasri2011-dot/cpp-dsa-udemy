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
        void insert(int value) { 
            if (root == nullptr) root = new Node(value);
            rInsert(root, value); 
        } 
        public:
        int minValue(Node*currentNode){
            while(currentNode->left != nullptr){
                currentNode = currentNode->left;
            }
            return currentNode->value;
        }
        int minValue(){
            return minValue(root);
        }
    

};

int main(){
     BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(47);

    cout << "\nMinValue from root:\n";
    cout << myBST->minValue(myBST->root);
    cout << "\n\nMinvalue from root->right";
    cout << myBST->minValue(myBST->root->right);
}