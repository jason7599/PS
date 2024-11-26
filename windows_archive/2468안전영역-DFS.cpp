#include <iostream>

using namespace std;

int mapSize;
int terrain[100][100];
bool visited[100][100];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int cnt;

void dfs(int x, int y) {
    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>mapSize;

    int minHeight = 100;
    int maxHeight = 1;
    for(int i=0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            int temp; cin>>temp;
            terrain[i][j] = temp;
            if(temp > maxHeight) maxHeight = temp;
            if(temp < minHeight) minHeight = temp;
        }
    }
}