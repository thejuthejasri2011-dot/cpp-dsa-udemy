#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
vector<int> heap;
int leftchild(int index){
    return 2 * index + 1;
}
int rightchild(int index){
    return 2 * index + 2;
}
int parent(int index){
    return(index-1)/2;
}
void Swap(int index1,int index2){
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}
public:
void printHeap(){
    cout << "\n [";
    for(size_t i=0;i<heap.size();i++){
        cout << heap[i];
        if(i < heap.size()-1){
            cout << " , ";
        }
    }
    cout << "]" << endl;
}

void insert(int value){
    heap.push_back(value);
    int current = heap.size()-1;
    while(current>0 && heap[current] > heap[parent(current)]){
        Swap(current,parent(current));
        current = parent(current);
    }
}
};

int main() {
    Heap* myHeap = new Heap();
    myHeap->insert(99);
    myHeap->insert(72);
    myHeap->insert(61);
    myHeap->insert(58);
    myHeap->insert(46);

    myHeap->printHeap();

};

