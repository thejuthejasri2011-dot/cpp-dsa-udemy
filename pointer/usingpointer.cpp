#include <iostream>

using namespace std;

int main() {

    int* num1 = new int(11);
    int* num2 = num1;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    
}