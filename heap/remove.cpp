#include<bits/stdc++.h>
using namespace std;

class Heap{
    private:
    vector<int> Heap;
    int leftchild(int index){
        return 2 * index + 1;
    }
    int rightchild(int index){
        return 2 * index + 2;
    }
    int parent(int index){
        return (index-1)/2;
    }
    void Swap(int index1,int index2){
        int temp = Heap[index1];
        Heap[index1] = Heap[index2];
        Heap[index2] = temp;
    }

    public:
    void printHeap(){
        cout << "\n[";
        for(size_t i=0;i<Heap.size();i++){
            cout << Heap[i];
            if(i<Heap.size()-1){
                cout << " ,";
            }
        }
        cout << "]" << endl;
    }


    void insert(int value){
        Heap.push_back(value);
        int current = Heap.size()-1;
        while(current > 0 && Heap[current] > Heap[parent(current)]){
            Swap(current,parent(current));
            current = parent(current);
        }
    }

    void sinkdown(int index){
        int maxIndex = index;
        while(true){
            int leftIndex = leftchild(index);
            int rightIndex = rightchild(index);
            if(rightIndex < Heap.size() && Heap[rightIndex] > Heap[maxIndex]){
                maxIndex = rightIndex;
            }
            if(leftIndex < Heap.size() && Heap[leftIndex] > Heap[maxIndex]){
            maxIndex = leftIndex;
        }
        if (maxIndex != index){
            Swap(index,maxIndex);
            index = maxIndex;
        } else {
            return;
        }
    }
}

    int remove(){
        if(Heap.empty()){
            return INT_MIN;
        }
        int maxvalue = Heap.front();
        if(Heap.size() == 1){
            Heap.pop_back();
        } else {
        Heap[0] = Heap.back();
        Heap.pop_back();
        sinkdown(0);
    }
    return maxvalue;
}
};



int main(){
    Heap* myHeap = new Heap;
    myHeap->insert(99);
    myHeap->insert(72);
    myHeap->insert(61);
    myHeap->insert(58);
    myHeap->insert(46);

    myHeap->remove();
    myHeap->printHeap();
}