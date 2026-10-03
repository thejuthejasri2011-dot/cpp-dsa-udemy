#include<bits/stdc++.h>
using namespace std;

void selectionsort(int array[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            int minIndex = i;
            if(array[j] < array[minIndex]){
                minIndex = j;
            

        if(i != minIndex){
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}
        }
    }

    int main(){
        int myarray[] = {6,4,2,5,1};
    int size = sizeof(myarray)/sizeof(myarray[0]);
    selectionsort(myarray,size);
    for(auto value : myarray){
        cout << value << " ";
    }
}