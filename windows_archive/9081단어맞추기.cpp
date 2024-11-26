#include <iostream>
#include <string>

using namespace std;

string nextVariant(string &str) {
    for(int i=str.length()-1; i>0; i--) {
        if(str[i]>str[i-1]) {
            char temp=str[i];
            str[i]=str[i-1];
            str[i-1]=temp;
            return str;
        }
    }
    return str;
}

int main() {
    int n;
    cin>>n;

    string input;
    for(int i=0; i<n; i++) {
        cin>>input;
        cout<<nextVariant(input)<<endl;
    }
}