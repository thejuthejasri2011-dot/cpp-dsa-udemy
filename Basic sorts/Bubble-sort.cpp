#include<bits/stdc++.h>
using namespace std;

void Bubblesort(int array[],int size){
for(int i=size-1;i>0;i--){
    for(int j=0;j<i;j++){
        if(array[j]>array[j+1]){
            int temp =array[j];
            array[j] =array[j+1];
            array[j+1] =temp;
        }
    }
}
};

int main(){
    int myarray[] = {6,4,2,5,1};
    int size = sizeof(myarray)/sizeof(myarray[0]);
    Bubblesort(myarray,size);
    for(auto value : myarray){
        cout << value << " ";
        
    }
}