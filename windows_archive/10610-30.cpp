#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input; cin>>input;

    int sum = 0; bool hasZero = false;
    vector<int> vec;
    for(char c : input) {
        int temp = c-'0';
        if(!temp) hasZero = true;
        sum+=temp;
        vec.push_back(temp);
    }

    if(sum%3 || !hasZero) {
        cout<<-1;
        return 0;
    }

    sort(vec.begin(), vec.end());
    string out = "";

    for(int i=vec.size()-1; i>=0; i--) {
        out+= (char)(vec[i]+48);
    }

    cout<<out;
}
