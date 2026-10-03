#include<bits/stdc++.h>
using namespace std;

void merge(int array[],int leftIndex,int midIndex,int rightIndex){
    int leftArraysize = midIndex-leftIndex+1;
    int rightArraysize = rightIndex-midIndex;
    int leftArray[leftArraysize];
    int rightArray[rightArraysize];
    for(int i=0;i<leftArraysize;i++){
        leftArray[i] = array[leftIndex+i];
    }
    for(int j=0;j<rightArraysize;j++){
        rightArray[j] = array[midIndex+1+j];
    }
    int index = leftIndex;
    int i = 0;
    int j = 0;
    while(i<leftArraysize && j<rightArraysize){
        if(leftArray[i] <= rightArray[j]){
            array[index] = leftArray[i];
            index++;
            i++;
        } else {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }
        while(i<leftArraysize){
            array[index] = leftArray[i];
            index++;
            i++;
        }
        while(j<rightArraysize){
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }


void mergesort(int array[],int leftIndex,int rightIndex){
    if(leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex-leftIndex)/2;
    mergesort(array,leftIndex,midIndex);
    mergesort(array,midIndex+1,rightIndex);
    merge(array,leftIndex,midIndex,rightIndex);
}

int main(){
    int myArray[] = {3,1,4,2};
    int size = sizeof(myArray)/sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size-1;
    mergesort(myArray,leftIndex,rightIndex);
    for(auto value:myArray){
        cout << value << " ";
    }
}