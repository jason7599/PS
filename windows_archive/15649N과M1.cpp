#include <iostream>
#include <string>

using namespace std;

int n,m;
bool visited[9];

string res = "";

void func(int x) {
    if(x==m) {cout<<res<<'\n'; return;}
    string cpy = res;
    for(int i=1; i<=n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        res+=to_string(i)+" ";
        func(x+1);
        res=cpy;
        visited[i]= false;
    }
}

int main() {
    cin>>n>>m;
    func(0);
}