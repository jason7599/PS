#include <iostream>

#define INF 987654321;

using namespace std;

int sizeX, sizeY, blocks, height[500][500];

int terraform(int targetHeight) {

    int time = 0;
    int blocksLeft = blocks;

    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            int delta = height[x][y] - targetHeight;
            if (delta > 0) time += 2 * delta; // needs mining
            else if (delta < 0) time += -delta; // needs placing
            blocksLeft += delta;
        }
    }

    return blocksLeft >= 0 ? time : INF;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> sizeX >> sizeY >> blocks;

    int lowest = INF;
    int highest = 0;

    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            int temp; cin >> temp;
            lowest = min(lowest, temp);
            highest = max(highest, temp);
            height[x][y] = temp;
        }
    }

    int ans1 = INF;
    int ans2 = lowest;

    for (int h = lowest; h <= highest; h++) {
        int temp = terraform(h);
        if (ans1 >= temp) {
            ans1 = temp;
            if (h > ans2)
                ans2 = h;
        }
    }

    cout << ans1 << ' ' << ans2;

}