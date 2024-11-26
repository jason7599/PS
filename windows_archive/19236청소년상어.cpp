#include <iostream>

using namespace std;

int ocean[4][4], direction[16], maxScore;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
bool dead[16];

void turnFish(int sharkX, int sharkY) {

    for (int fishIndex = 0; fishIndex < 16; fishIndex++) {
        if (dead[fishIndex]) continue;
        int x, y;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (ocean[i][j] == fishIndex) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int turnDirection = direction[fishIndex];
        int turnCount = 0;
        while (turnCount != 8) {
            int nx = x + dx[turnDirection];
            int ny = y + dy[turnDirection];
            if (nx < 0 || nx == 4 || ny < 0 || ny == 4
                || (nx == sharkX && ny == sharkY)) {
                turnDirection = (turnDirection + 1) % 8;
                turnCount++;
                continue;
            }
            int fishToSwap = ocean[nx][ny];
            ocean[nx][ny] = ocean[x][y];
            ocean[x][y] = fishToSwap;
            direction[fishIndex] = turnDirection;
            break;
        }
    }
}

void sharkAttack(int sharkX, int sharkY, int sharkDirection, int score) {

    turnFish(sharkX, sharkY);

    int directionCopy[16];
    int oceanCopy[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            directionCopy[4 * i + j] = direction[4 * i + j];
            oceanCopy[i][j] = ocean[i][j];
        }
    }

    for (int range = 1; ; range++) {

        int nx = sharkX + dx[sharkDirection] * range;
        int ny = sharkY + dy[sharkDirection] * range;

        if (nx < 0 || nx == 4 || ny < 0 || ny == 4) break;
        if (dead[ocean[nx][ny]]) continue;

        dead[ocean[nx][ny]] = true;
        sharkAttack(nx, ny, direction[ocean[nx][ny]], score + ocean[nx][ny] + 1);
        dead[ocean[nx][ny]] = false;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                direction[4 * i + j] = directionCopy[4 * i + j];
                ocean[i][j] = oceanCopy[i][j];
            }
        }

    }

    if (score > maxScore) maxScore = score;

}

int main() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int fish, dir;
            cin >> fish >> dir;
            ocean[i][j] = fish - 1;
            direction[fish - 1] = dir - 1;
        }
    }

    dead[ocean[0][0]] = true;

    sharkAttack(0, 0, direction[ocean[0][0]], ocean[0][0] + 1);

    cout << maxScore;


}

