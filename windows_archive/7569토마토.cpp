#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int sizeX, sizeY, sizeZ;
int tomato[100][100][100];

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

// void printTomato() {
//     cout<<"Tomato===========\n";
//     for(int z=0; z<sizeZ; z++) {
//         cout<<"Z:"<<z<<'\n';
//         for(int y=0; y<sizeY; y++) {
//             for(int x=0; x<sizeX; x++) {
//                 cout<<tomato[x][y][z]<<' ';
//             }
//             cout<<'\n';
//         }
//     }
// }

int main() {
    cin>>sizeX>>sizeY>>sizeZ;

    int tomatoesLeft = 0;
    queue<tuple<int,int,int>> q;
    for(int z=0; z<sizeZ; z++) {
        for(int y=0; y<sizeY; y++) {
            for(int x=0; x<sizeX; x++) {
                int temp; cin>>temp;
                tomato[x][y][z] = temp;
                if(!temp) tomatoesLeft++;
                else if(temp==1) q.push({x,y,z});
            }
        }
    }

    int days = 0;
    while(true) {
        bool deadlock = true; //바뀐게 없을 때
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int z = get<2>(q.front());
            q.pop();
            for(int k=0; k<6; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nz = z + dz[k];

                if(nx<0 || nx==sizeX 
                || ny<0 || ny==sizeY
                || nz<0 || nz==sizeZ //익지 않은 토마토에 대해서만
                || tomato[nx][ny][nz]) continue;

                deadlock = false;
                tomatoesLeft--;
                tomato[nx][ny][nz] = 1;
                q.push({nx,ny,nz});
            }
        }

        // printTomato();
        if(deadlock) break;
        days++;
    }

    if(tomatoesLeft) cout<<-1;
    else cout<<days;
}