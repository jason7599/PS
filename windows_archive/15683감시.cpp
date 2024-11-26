#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int sizeX, sizeY, office[8][8], directions[8];
int grayArea, minGrayArea = 987654321;
vector<pair<int, int>> cameras;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool checked[8][8];

void rotateCameras(int camIndex = 0);
int eliminateGrayAreas(int camX, int camY, int direction);
int evalOffice();

int main() {

    cin >> sizeX >> sizeY;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            int temp; cin >> temp;
            office[i][j] = temp;
            if (!temp) grayArea++;
            else if (temp != 6)
                cameras.push_back({ i, j });
        }
    }

    rotateCameras();

    cout << minGrayArea;

}

void rotateCameras(int camIndex) {

    if (camIndex == cameras.size()) {
        int res = evalOffice();
        if (res < minGrayArea)
            minGrayArea = res;
        memset(checked, 0, sizeof(checked));
        return;
    }

    int mode = office[cameras[camIndex].first][cameras[camIndex].second];

    if (mode == 2) {
        for (int d = 0; d < 2; d++) {
            directions[camIndex] = d;
            rotateCameras(camIndex + 1);
        }
    }
    else if (mode == 5) rotateCameras(camIndex + 1);
    else {
        for (int d = 0; d < 4; d++) {
            directions[camIndex] = d;
            rotateCameras(camIndex + 1);
        }
    }

}

int eliminateGrayAreas(int camX, int camY, int direction) {

    int eliminated = 0;
    int nx = camX;
    int ny = camY;

    while (true) {

        nx += dx[direction];
        ny += dy[direction];

        if (nx < 0 || nx == sizeX || ny < 0 || ny == sizeY
            || office[nx][ny] == 6) break;

        if (!checked[nx][ny] && !office[nx][ny]) {
            checked[nx][ny] = true;
            eliminated++;
        }

    }

    return eliminated;

}

int evalOffice() {

    int res = grayArea;

    for (int camIndex = 0; camIndex < cameras.size(); camIndex++) {

        int camX = cameras[camIndex].first;
        int camY = cameras[camIndex].second;
        int mode = office[camX][camY];
        int direction = directions[camIndex];

        if (mode == 1)
            res -= eliminateGrayAreas(camX, camY, direction);
        else if (mode == 2) {
            res -= eliminateGrayAreas(camX, camY, direction);
            res -= eliminateGrayAreas(camX, camY, direction + 2);
        }
        else if (mode == 3) {
            res -= eliminateGrayAreas(camX, camY, direction);
            res -= eliminateGrayAreas(camX, camY, (direction + 1) % 4);
        }
        else if (mode == 4) {
            res -= eliminateGrayAreas(camX, camY, direction);
            res -= eliminateGrayAreas(camX, camY, (direction + 1) % 4);
            res -= eliminateGrayAreas(camX, camY, (direction + 2) % 4);
        }
        else if (mode == 5) {
            res -= eliminateGrayAreas(camX, camY, 0);
            res -= eliminateGrayAreas(camX, camY, 1);
            res -= eliminateGrayAreas(camX, camY, 2);
            res -= eliminateGrayAreas(camX, camY, 3);
        }

    }

    return res;

}