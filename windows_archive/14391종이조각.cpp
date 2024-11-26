#include <iostream>

using namespace std;

int sizeX, sizeY, maxScore;
char board[4][4];
bool taken[4][4];

string bestPath;

pair<int, int> nextCoord() {

    for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++)
            if (!taken[i][j]) return { i, j };

    return { -1, -1 };
}

void func(pair<int, int> coord = { 0, 0 }, int score = 0, string path = "") {

    int x = coord.first;
    if (x == -1) {
        if (score > maxScore) {
            maxScore = score;
            bestPath = path;
        }
        return;
    }
    int y = coord.second;

    int len;
    int scoreDelta = 0;
    // 가로로. 길이 1인 것 여기서 계산
    for (len = 0; y + len < sizeY; len++) {
        if (taken[x][y + len]) break;
        taken[x][y + len] = true;
        scoreDelta = scoreDelta * 10 + board[x][y + len] - '0';
        func(nextCoord(), score + scoreDelta);
    }
    // taken 해둔거 취소. len 0 빼고
    while (--len) taken[x][y + len] = false;

    scoreDelta = board[x][y] - '0';
    // 세로. 길이 1은 여기서 안함
    for (len = 1; x + len < sizeX; len++) {
        if (taken[x + len][y]) break;
        taken[x + len][y] = true;
        scoreDelta = scoreDelta * 10 + board[x + len][y] - '0';
        func(nextCoord(), score + scoreDelta);
    }
    // taken 취소, len 0까지
    while (len--) taken[x + len][y] = false;

    // 취소해주는 과정 필요한가?
}

int main() {

    cin >> sizeX >> sizeY;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            char temp; cin >> temp;
            board[i][j] = temp;
        }
    }

    func();

    cout << maxScore;

}