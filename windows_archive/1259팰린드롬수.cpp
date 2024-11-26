#include <iostream>
#include <string>

using namespace std;

int main() {
    while(1) {
        string input; cin>>input;
        if(input=="0") break;
        bool palindrome = true;
        for(int i = 0; i<input.length()/2; i++) {
            if(input[i]!=input[input.length()-i-1]) {
                palindrome=false;
                break;
            }
        }
        if(palindrome) cout<<"yes";
        else cout<<"no";
        cout<<"\n";
    }
}