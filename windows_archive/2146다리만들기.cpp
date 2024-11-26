#include <iostream>
#include <queue>

using namespace std;

int mapSize;
int map[100][100];
bool visited[100][100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int islandCount;

void mapDockAreas();
int findMinLength(int islandNum);

void debug();

int main() {
    
    cin>>mapSize;

    //육지= -1, 바다= 0
    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            int temp; cin>>temp;
            map[i][j] = temp ? -1 : 0;
        }
    }

    mapDockAreas();
    // debug();

    int minLength = 2147483647;

    for(int i=1; i<=islandCount; i++) {
        int temp = findMinLength(i);
        // cout<<temp<<'\n';
        if(temp < minLength) minLength = temp;
    }

    cout<<minLength;
}

//육지 테두리
void mapDockAreas() {
    int islandNum=0;
    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) { //육지에서 확인
            if(visited[i][j] || map[i][j] != -1) continue;

            visited[i][j] = true; islandNum++;
            queue<pair<int,int>> q; q.push({i,j});
            
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                bool isDock = false;
                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx<0 || nx==mapSize 
                    || ny<0 || ny==mapSize
                    || visited[nx][ny]) continue;
                    //육지 기준 인접한 바다 칸이 하나라도 있으면 테두리
                    if(map[nx][ny] == 0) {
                        isDock = true;
                        continue; //이거 불안
                    }
                    q.push({nx,ny}); visited[nx][ny] = true;
                }
                //해당 칸 색칠
                if(isDock) map[x][y] = islandNum;
            }
        }
    }
    islandCount = islandNum;
}

int findMinLength(int islandNum) {
    
    queue<pair<int,int>> q;
    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            visited[i][j] = false;
            if(map[i][j] == islandNum) {
                q.push({i,j}); visited[i][j]=true;
            }
        }
    }

    int length = 0;
    while(!q.empty()) {
        int batch = q.size();
        for(int i=0; i<batch; i++) { //한칸씩 나갈때마다 length++해야하니까
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx<0 || nx==mapSize
                || ny<0 || ny==mapSize
                || visited[nx][ny]
                || map[nx][ny] == islandNum
                || map[nx][ny] == -1) continue; //얘도 불안
                
                if(map[nx][ny] != 0) return length;

                q.push({nx,ny}); visited[nx][ny] = true;
            }
        }
        length++;
    }
}

void debug() {
    cout<<"map===============\n";
    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            printf("%2d",map[i][j]);
        }
        cout<<'\n';
    }
}