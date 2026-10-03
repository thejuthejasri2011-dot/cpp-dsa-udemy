#include<bits/stdc++.h>
using namespace std;

void swap(int array[],int firstIndex,int endIndex){
    int temp = array[firstIndex];
   array[firstIndex] = array[endIndex];
   array[endIndex] = temp;

}

int pivot(int array[],int pivotIndex,int endIndex){
    int swapIndex = pivotIndex;
    for(int i=pivotIndex+1;i<=endIndex;i++){
        if(array[i] < array[pivotIndex]){
        swap(array,swapIndex,i);
    }
}

swap(array,pivotIndex,swapIndex);
    return swapIndex;
}

void quicksort(int array[],int leftIndex,int rightIndex){
    if( leftIndex < rightIndex){
        int pivotIndex = pivot(array,leftIndex,rightIndex);
        quicksort(array,leftIndex,pivotIndex-1);
        quicksort(array,pivotIndex+1,rightIndex);
    }
}

int main(){
    int myArray[] = {4,6,1,7,3,2,5};
    int size = sizeof(myArray)/sizeof(myArray[0]);
    quicksort(myArray,0,size-1);
    
    for(auto value : myArray){
        cout << value << " ";
    }
}