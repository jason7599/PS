#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    int n, m;
    cin>>n>>m;

    map<string, bool> s;

    for(int i=0; i<n; i++) {
        string temp;
        cin>>temp;
        s[temp] = true;
    }

    int res = 0;

    for(int i=0; i<m; i++) {
        string temp;
        cin>>temp;
        if(s[temp]) res++;
    }

    cout<<res;

}