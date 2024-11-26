#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int sizeX, sizeY;

bool isBlocked[100][100];
bool visited[100][100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {

    cin>>sizeX>>sizeY;
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int startX, startY, endX, endY;
        cin>>startX>>startY>>endX>>endY;

        for(int x = startX; x < endX; x++)
            for(int y = startY; y < endY; y++)
                isBlocked[y][x]=true;
    }

    vector<int> areaSizes;
    for(int x=0; x<sizeX; x++) {
        for(int y=0; y<sizeY; y++) {
            if(visited[x][y] || isBlocked[x][y]) continue;

            int areaSize = 0;
            queue<pair<int,int>> q;
            q.push({x,y});
            visited[x][y] = true;

            while(!q.empty()) {
                int curX = q.front().first;
                int curY = q.front().second;
                areaSize++; q.pop();

                for(int k =0; k<4; k++) {
                    int nx = curX + dx[k];
                    int ny = curY + dy[k];

                    if(nx<0 || nx==sizeX || ny<0 || ny==sizeY) continue;
                    if(isBlocked[nx][ny] || visited[nx][ny]) continue;

                    q.push({nx,ny}); visited[nx][ny]=true;
                }
            }
            areaSizes.push_back(areaSize);
        }
    }
    
    sort(areaSizes.begin(), areaSizes.end());

    cout<<areaSizes.size()<<'\n';
    for(int size : areaSizes) 
        cout<<size<<' ';


}