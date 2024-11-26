#include <iostream>
#include <queue>

using namespace std;

int sizeX, sizeY;

int map[50][50];
bool visited[50][50];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void printMap() {
    cout<<"Map=====================\n";
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            map[i][j] = temp - '0';
        }
    }

    int sum = 0;
    while(true) {
        bool deadlock = true; //
        for(int i=1; i<sizeX-1; i++) {
            for(int j=1; j<sizeY-1; j++) {
                if(visited[i][j]) continue;

                int cur = map[i][j];
                visited[i][j] = true;
                queue<pair<int,int>> traverseQ;
                queue<pair<int,int>> fillQ;
                traverseQ.push({i,j});
                fillQ.push({i,j});

                int lowestWall = 9;
                bool canFill = true;
                while(!traverseQ.empty()) {
                    int x = traverseQ.front().first;
                    int y = traverseQ.front().second;
                    traverseQ.pop();

                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(visited[nx][ny]) continue;

                        if(map[nx][ny] < cur) {
                            canFill = false;
                            break;
                        }
                        else if(map[nx][ny] == cur) {
                            if(nx==0 || nx==sizeX-1 || ny==0 || ny==sizeY-1) {
                                canFill = false;
                                break;
                            }
                            visited[nx][ny] = true;
                            traverseQ.push({nx,ny});
                            fillQ.push({nx,ny});
                        }
                        else { //벽 만남
                            if(lowestWall > map[nx][ny]) 
                                lowestWall = map[nx][ny];
                        }
                        

                    }
                    if(!canFill) break;
                }

                for(int a=0; a<sizeX; a++) 
                    for(int b=0; b<sizeY; b++)
                        visited[a][b] = false;

                if(!canFill) continue;
                deadlock = false;

                while(!fillQ.empty()) {
                    int x = fillQ.front().first;
                    int y = fillQ.front().second;
                    fillQ.pop();

                    sum+= lowestWall - map[x][y];
                    map[x][y] = lowestWall;
                }
                // printMap();
                // cout<<"sum="<<sum<<endl;
            }   
        }
        if(deadlock) break;
    }

    cout<<sum;
}