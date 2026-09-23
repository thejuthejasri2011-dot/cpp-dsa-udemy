#include<bits/stdc++.h>
using namespace std;
bool isBalancedparentheses(const string& parentheses) {
    stack<char> s;
    for(char c: parentheses){
        if(c=='('){
            s.push(c);
        }
        else if(c==')'){
            if(s.empty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    cout << isBalancedparentheses("(()") << endl;
}