#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;

bool painting[500][500];
bool visited[500][500];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            int temp; cin>>temp;
            painting[i][j] = temp;
        }
    }

    int count = 0;
    int largest = 0;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            if(visited[i][j] || !painting[i][j]) continue;
            int size = 0;
            count++;
            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j] = true;
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                size++;
                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx<0 || nx==sizeX || ny<0 || ny==sizeY
                    || visited[nx][ny] || !painting[nx][ny]) continue;
                    q.push({nx,ny}); visited[nx][ny] = true;
                }
            }
            if(size > largest) largest = size;
        }
    }

    cout<<count<<'\n';
    cout<<largest;
}