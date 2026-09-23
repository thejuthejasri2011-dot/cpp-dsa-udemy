#include <bits/stdc++.h>
using namespace std;
string reverseString(const string& str) {
    stack<char> s;
    string reversedString = "";
    for(char c: str){
        s.push(c);
    }
    while(!s.empty()){
        reversedString += s.top();
        s.pop();
    }
   return reversedString;
}

int main() {
    string str = "hello";
    cout << reverseString(str) << endl;
    return 0;
}
