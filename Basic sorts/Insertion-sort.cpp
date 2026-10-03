#include<bits/stdc++.h>
using namespace std;

void insertionsort(int array[],int size){
    for(int i=1;i<size;i++){
        int temp = array[i];
        int j=i-1;
        while(j>-1 && temp<array[j]){
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}

  int main(){
        int myarray[] = {6,4,2,5,1};
    int size = sizeof(myarray)/sizeof(myarray[0]);
    insertionsort(myarray,size);
    for(auto value : myarray){
        cout << value << " ";
    }
}