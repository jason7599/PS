#include <iostream>
#include <queue>

using namespace std;

bool cheese[100][100];
int airCount[100][100];
bool visited[100][100];

int sizeX, sizeY;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void printCheese();

int main() {
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            int temp; cin>>temp;  
            cheese[i][j] = temp;
        }
    }

    int hours = 0;

    while(true) {
        //
        for(int i=0; i<sizeX; i++) {
            for(int j=0; j<sizeY; j++) { //공기 기준으로 탐색
                if(visited[i][j] || cheese[i][j]) continue;

                queue<pair<int,int>> traverseQ;
                traverseQ.push({i,j});
                visited[i][j] = true; 
                bool isBlocked = true; //막혀 있나

                queue<pair<int,int>> meltQ;
                while(!traverseQ.empty()) {
                    int x = traverseQ.front().first;
                    int y = traverseQ.front().second;
                    traverseQ.pop();

                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx<0 || nx==sizeX || ny<0 || ny==sizeY || visited[nx][ny]) continue;
                        if(!nx || nx==sizeX-1 || !ny || ny==sizeY-1 ) isBlocked = false; //안 막힘
                        
                        if(!cheese[nx][ny]) { //공기면
                            traverseQ.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                        else {
                            meltQ.push({nx,ny}); //치즈면
                        }
                    }
                }

                if(!isBlocked) { //안 막혀 있다면
                    while(!meltQ.empty()) {
                        int x = meltQ.front().first;
                        int y = meltQ.front().second;
                        // for(int k=0; k<4; )
                        airCount[x][y]++; //공기 수 ++;
                        meltQ.pop();
                    }
                }
            }
        }

        // printCheese();

        //공기 수가 2 이상이면 녹인다
        //다 녹았는지 확인
        bool noneLeft = true;
        for(int i=0; i<sizeX; i++) {
            for(int j=0; j<sizeY; j++) {
                visited[i][j] = false;
                if(airCount[i][j] > 1)
                    cheese[i][j] = false;
                if(!cheese[i][j]) continue;
                noneLeft = false;
                airCount[i][j] = 0;
            }
        }

        hours++;
        if(noneLeft) break;
    }

    cout<<hours;
}

void printCheese() {
    cout<<"cheese=============\n";
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            if(cheese[i][j]) cout<<1<<' ';
            else cout<<0<<' ';
        }
        cout<<endl;
    }

    cout<<"airCount=============\n";
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            cout<<airCount[i][j]<<' ';
        }
        cout<<endl;
    }

}