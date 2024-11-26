#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;
bool cheese[100][100];
bool cheese_cpy[100][100];
bool visited[100][100];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {

    cin>>sizeX>>sizeY;

    int cheeseToMelt = 0;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            int temp; cin>>temp;
            cheese[i][j] = temp;
            cheese_cpy[i][j] = temp;
            if(temp) cheeseToMelt++;
        }
    }
    // cout<<cheeseToMelt<<endl;

    if(!cheeseToMelt) { //애초에 없으면
        cout<<"0\n0";
        return 0;
    }

    int hours = 0;
    while(true) {
        //녹을 부분 계산
        cheeseToMelt = 0;
        for(int i=0; i<sizeX; i++) {
            for(int j=0; j<sizeY; j++) {
                if(cheese[i][j] || visited[i][j]) continue;

                bool isBlocked = true;
                queue<pair<int,int>> traverseQ;
                traverseQ.push({i,j});
                visited[i][j] = true;

                queue<pair<int,int>> meltQ; //녹일 좌표들
                while(!traverseQ.empty()) {
                    int x = traverseQ.front().first;
                    int y = traverseQ.front().second;
                    traverseQ.pop();

                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx<0 || nx==sizeX || ny<0 || ny==sizeY || visited[nx][ny]) continue;

                        if(nx==0 || nx==sizeX-1 || ny==0 || ny==sizeY-1) isBlocked = false; //외부에 닿았으면
                        
                        visited[nx][ny] = true;
                        if(cheese[nx][ny]) meltQ.push({nx,ny});
                        else traverseQ.push({nx,ny});
                    }
                }

                cheeseToMelt += meltQ.size();
                // cout<<"cheeseToMelt = "<<cheeseToMelt<<endl;

                if(!isBlocked) {
                    while(!meltQ.empty()) {
                        int x = meltQ.front().first;
                        int y = meltQ.front().second;
                        cheese_cpy[x][y] = false;
                        meltQ.pop();
                    }
                }
            }
        }
        hours++;

        bool noneLeft = true;
        for(int i=0; i<sizeX; i++) {
            for(int j=0; j<sizeY; j++) {
                if(cheese_cpy[i][j]) noneLeft = false;
                cheese[i][j] = cheese_cpy[i][j];
                visited[i][j] = false;
            }
        }
        if(noneLeft) break;
    }

    cout<<hours<<'\n'<<cheeseToMelt;
}