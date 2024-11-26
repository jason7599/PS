#include <iostream>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

// studentInfo[학생 번호] = [좋아하는 학생 4명 번호];
int mapSize, studentInfo[401][4], map[20][20];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> studentOrder;

void printMap() {
    cout << '\n';
    FOR(i, mapSize) {
        FOR(j, mapSize) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool chck(int x, int y) {
    return !(x < 0 || x == mapSize || y < 0 || y == mapSize);
}

void placeStudent(int studentIndex) {

    int studentNumber = studentOrder[studentIndex];

    // 첫번째 학생 위치는 늘 같음
    if (!studentIndex) {
        map[1][1] = studentNumber;
        return;
    }

    int mostFriends = -1;
    int mostBlanks = -1;
    int bestX, bestY;

    FOR(x, mapSize) {

        bool breakFlag = false;

        FOR(y, mapSize) {
            // occupied
            if (map[x][y]) continue;

            int friends = 0; // :( 
            int blanks = 0;

            FOR(d, 4) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                if (chck(nx, ny)) {
                    if (map[nx][ny]) { // 친구인지 확인
                        FOR(f, 4) {
                            if (map[nx][ny] == studentInfo[studentNumber][f]) {
                                friends++;
                                break;
                            }
                        }
                    }
                    else blanks++; // 빈칸
                }
            }

            if (friends > mostFriends) {
                if (friends == 4) {
                    breakFlag = true;
                    break; // cant get better
                }
                bestX = x;
                bestY = y;
                mostFriends = friends;
                mostBlanks = blanks;
            }
            else if (friends == mostFriends) {
                if (blanks > mostBlanks) {
                    bestX = x;
                    bestY = y;
                    mostBlanks = blanks;
                }
            }

        }
        if (breakFlag) break;
    }

    map[bestX][bestY] = studentNumber;
}

int calculateScore() {
    int score = 0;

    FOR(x, mapSize) {
        FOR(y, mapSize) {
            int studentNumber = map[x][y];
            int adjFriendCount = 0;
            FOR(d, 4) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (chck(nx, ny)) {
                    FOR(f, 4) {
                        if (map[nx][ny] == studentInfo[studentNumber][f]) {
                            adjFriendCount++;
                            break;
                        }
                    }
                }
            }
            if (adjFriendCount) {
                if (adjFriendCount == 1) score += 1;
                else if (adjFriendCount == 2) score += 10;
                else if (adjFriendCount == 3) score += 100;
                else if (adjFriendCount == 4) score += 1000;
                else cout << "!?\n";
            }
        }
    }

    return score;
}

int main() {

    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> mapSize;

    FOR(i, mapSize * mapSize) {
        int studentNum; cin >> studentNum;
        studentOrder.push_back(studentNum);
        FOR(j, 4) 
            cin >> studentInfo[studentNum][j];
    }

    FOR(i, mapSize * mapSize) {
        placeStudent(i);
        printMap();
    }

    cout << calculateScore();

}