#include <iostream>

using namespace std;

int dist[6];
int dir[6];
bool check[6];

int main() {

    int n; cin>>n;

    for(int i=0; i<6; i++) {
        int direction, length;
        cin>>direction>>length;
        check[direction] = !check[direction];
        dir[i] = direction;
        dist[i] = length;
    }

    for(int i=0; i<6; i++) {
        if(check[dir[i]] && check[dir[(i+1)%6]]) {
            cout << n * (dist[i] * dist[(i+1)%6] - dist[(i+3)%6] * dist[(i+4)%6]);
            return 0;
        }
    }

}