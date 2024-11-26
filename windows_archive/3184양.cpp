#include <iostream>
#include <queue>
#include <string>

using namespace std;

int map[250][250];
bool visited[250][250];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int row, col;
    cin>>row>>col;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            char temp;
            cin>>temp;
            //0:nothing 1:sheep 2:wolf 3:fence
            if(temp=='#')
                map[i][j]=3;
            else if(temp=='o')
                map[i][j]=1;
            else if(temp=='v')
                map[i][j]=2;
        }
    }

    int globalSheepCnt=0, globalWolfCnt=0;
    int areaNum=1;
    for(int x=0; x<row; x++) {
        for(int y=0; y<col; y++) {
            if(visited[x][y] || map[x][y]==3) continue;
            // cout<<"Traversing area["<<areaNum<<"] from ["<<x<<"]["<<y<<"]\n";
            int sheepCnt=0, wolfCnt=0;
            queue<pair<int,int>> q;
            q.push({x,y});
            visited[x][y]=true;
            if(map[x][y]==1) sheepCnt++;
            else if(map[x][y]==2) wolfCnt++;
            while(!q.empty()) {
                int curX = q.front().first;
                int curY = q.front().second;
                q.pop();
                for(int k=0; k<4; k++) {
                    int nx = curX + dx[k];
                    int ny = curY + dy[k];
                    if(nx<0 || nx==row || ny<0 || ny==col) continue;
                    if(visited[nx][ny] || map[nx][ny]==3) continue;
                    if(map[nx][ny]==1) sheepCnt++;
                    else if(map[nx][ny]==2) wolfCnt++;
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
            // cout<<"area["<<areaNum++<<"] has "<<sheepCnt<<" sheep and "<<wolfCnt<<" wolves\n";
            if(sheepCnt>wolfCnt) globalSheepCnt+=sheepCnt;
            else globalWolfCnt+=wolfCnt;
        }
    }

    cout<<globalSheepCnt<<" "<<globalWolfCnt;
}