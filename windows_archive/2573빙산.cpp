#include <iostream>
#include <queue>

using namespace std;

int n,m;

int iceberg[300][300];
int iceberg_cpy[300][300];
bool visited[300][300];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int globalWarming() {
    int years = 0;

    while(true) {
        
        int iceberg_cnt = 0;
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(!iceberg[i][j] || visited[i][j]) continue;

                queue<pair<int,int>> q; q.push({i,j});
                visited[i][j] = true; iceberg_cnt++;

                if(iceberg_cnt==2) return years;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second; q.pop();

                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx==0 || nx==n-1 || ny==0 || ny==m-1) continue; //이거 안해도 되려나
                        if(!iceberg[nx][ny] || visited[nx][ny]) continue;

                        visited[nx][ny] = true; q.push({nx,ny});
                    }
                }
            }
        }
        if(!iceberg_cnt) return 0;

        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(!iceberg[i][j]) continue;
                int abutCount = 0;
                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(!iceberg_cpy[nx][ny]) abutCount++;
                }
                iceberg[i][j]-=abutCount;
                if(iceberg[i][j] < 0) iceberg[i][j] = 0;
            }
        }

        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                iceberg_cpy[i][j]=iceberg[i][j];
                visited[i][j]=false;
            }
        }

        years++;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int input; cin>>input;
            iceberg[i][j] = input;
            iceberg_cpy[i][j] = input;
        }
    }

    cout<<globalWarming();
}