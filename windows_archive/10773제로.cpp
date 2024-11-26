#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n; cin>>n;

    stack<int> S;

    for(int i=0; i<n; i++) {
        int input; cin>> input;
        if(input) S.push(input);
        else S.pop();
    }

    int sum=0;
    while(!S.empty()) {
        sum+=S.top();
        S.pop();
    }

    cout<<sum;

}