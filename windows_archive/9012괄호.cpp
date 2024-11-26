#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n; cin>>n;

    for(int i=0; i<n; i++) {
        string input;
        cin>>input;
        stack<char> s;
        for(char c : input) {
            if(!s.empty() && s.top() == '(' && c == ')')
                s.pop();
            else s.push(c);
        }
        if(s.empty()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}