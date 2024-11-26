#include <iostream>
#include <queue>

using namespace std;

int n;

char grid[100][100];
bool visited[100][100];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int countSections(bool colorblind) {

    int sectionCount = 0;

    if(colorblind) {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                visited[i][j] = false;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j]) continue;

            char cur = grid[i][j];
            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j] = true;
            sectionCount++;

            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx<0 || nx==n || ny<0 || ny==n) continue;
                    if(visited[nx][ny]) continue;

                    if(colorblind) {
                        if((cur == grid[nx][ny]) || (cur=='R' && grid[nx][ny]=='G') || (cur=='G' && grid[nx][ny]=='R')) {
                            q.push({nx,ny});
                            visited[nx][ny]=true;
                        }
                    }
                    else {
                        if(cur != grid[nx][ny]) continue;
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
            }
        }
    }
    return sectionCount;
}

int main() {

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            char temp; cin>>temp;
            grid[i][j] = temp;
        }
    }

    cout<<countSections(false)<<' '<<countSections(true);

}