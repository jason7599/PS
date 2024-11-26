#include <iostream>
#include <queue>

using namespace std;

int dist[100001];
bool visited[100001];

int calcTime(int start, int dest) {
    if(start == dest) return 0;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<3; i++) {
            int next = cur;
            if(i==0) next++;
            else if(i==1) next--;
            else if(i==2) next*=2;
            
            if(next < 0 || next >= 100001) continue;
            if(!visited[next]) {
                q.push(next);
                dist[next] = dist[cur]+1;
                if(next == dest) return dist[next];
                visited[next] = true;
            }
        }
    }
}


int main() {

    int start, dest;
    cin>> start>> dest;

    cout<<calcTime(start, dest);

}