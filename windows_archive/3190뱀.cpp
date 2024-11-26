#include <iostream>
#include <queue>

using namespace std;

int boardSize, appleCount, turnCount, ans;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int directionIndex;
bool apples[100][100];
bool snake[100][100];
int headX, headY;
queue<pair<int, int>> snakeQ;
queue<pair<int, bool>> schedule;

// void printBoard() {

//     cout << "time: " << ans << ", direction: ";
//     if (directionIndex == 0) cout << "right";
//     else if (directionIndex == 1) cout << "up";
//     else if (directionIndex == 2) cout << "left";
//     else cout << "down";
//     cout << '\n';

//     for (int i = 0; i < boardSize; i++) {
//         cout << '=';
//     }

//     cout << '\n';
//     for (int i = 0; i < boardSize; i++) {
//         for (int j = 0; j < boardSize; j++) {
//             if (apples[i][j]) cout << 'O';
//             else if (snake[i][j]) cout << 'S';
//             else cout << '-';
//         }
//         cout << '\n';
//     }
//     for (int i = 0; i < boardSize; i++) {
//         cout << '=';
//     }
//     cout << '\n';
// }

int main() {

    cin >> boardSize >> appleCount;

    while (appleCount--) {
        int x, y; cin >> x >> y;
        apples[x - 1][y - 1] = true;
    }

    snake[0][0] = true;
    snakeQ.push({ 0, 0 });

    cin >> turnCount;

    while (turnCount--) {

        int time; char dir;
        cin >> time >> dir;
        schedule.push({ time, dir == 'D' });

    }

    schedule.push({ 987654321, false });

    while (true) {

        int time = schedule.front().first - ans;
        bool turnRight = schedule.front().second;
        schedule.pop();

        while (time--) {

            ans++;

            int nx = headX + dx[directionIndex];
            int ny = headY + dy[directionIndex];

            if (nx < 0 || nx == boardSize || ny < 0 || ny == boardSize
                || snake[nx][ny]) {
                cout << ans;
                return 0;
            }

            headX = nx;
            headY = ny;

            if (apples[headX][headY])
                apples[headX][headY] = false;

            else {
                int tailX = snakeQ.front().first;
                int tailY = snakeQ.front().second;
                snake[tailX][tailY] = false;
                snakeQ.pop();
            }


            snake[headX][headY] = true;
            snakeQ.push({ headX, headY });

            // printBoard();
        }

        if (turnRight) directionIndex = (directionIndex + 3) % 4;
        else directionIndex = (directionIndex + 1) % 4;

    }

}