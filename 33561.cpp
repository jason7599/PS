#include <bits/stdc++.h>

using namespace std;

int map_size;
int map_tiles[500][500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> map_size;
    for (int y = 0; y < map_size; y++) {
        for (int x = 0; x < map_size; x++)
            cin >> map_tiles[y][x];
    }

    int n_improves;
    cin >> n_improves;

    vector<int> improves(n_improves);
    for (int& n : improves)
        cin >> n;
    
    sort(improves.begin(), improves.end(), greater<int>());

    int max_val = 0;

    for (int y = 0; y < map_size; y++) {
        for (int x = 0; x < map_size; x++) {
            int val = 0;
            int improve_idx = 0;
            
        }
    }

    cout << max_val << '\n';
}