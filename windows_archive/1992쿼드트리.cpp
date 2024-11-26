#include <iostream>
#include <string>

using namespace std;

int imageSize;
bool image[64][64];

string compress(int baseX, int baseY, int length) {

    if (length == 1) return to_string(image[baseX][baseY]);

    int half = length / 2;

    string results[4];

    results[0] = compress(baseX, baseY, half);
    results[1] = compress(baseX, baseY + half, half);
    results[2] = compress(baseX + half, baseY, half);
    results[3] = compress(baseX + half, baseY + half, half);

    for (int i = 0; i < 4; i++)
        if (results[i][0] == '(' || results[i] != results[0])
            return '(' + results[0] + results[1] + results[2] + results[3] + ')';

    return results[0];

}

int main() {

    cin >> imageSize;

    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageSize; j++) {
            char temp; cin >> temp;
            image[i][j] = temp == '1';
        }
    }

    cout << compress(0, 0, imageSize);

}