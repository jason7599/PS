#include <iostream>
#include <vector>

using namespace std;

vector<int> computers[101];
bool visited[101];
int count = -1;

void dfs(int start) {
    // cout<<"at "<<start<<" now\n";
    visited[start]=true;
    ::count++;
    for(int pc : computers[start]) {
        if(!visited[pc]) dfs(pc);
    }
}

int main() {

    int n; cin>>n;
    int m; cin>>m;

    for(int i=0; i<m; i++) {
        int from, to;
        cin>>from>>to;
        computers[from].push_back(to);
        computers[to].push_back(from);
    }

    dfs(1);
    
    cout<<::count;
}