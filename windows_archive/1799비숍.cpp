#include <iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int boardSize, maxBishops;
bool board[10][10];

void printBoard() {
    cout << '\n';
    FOR(i, boardSize) {
        FOR(j, boardSize)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void markBoard(int x, int y) {
    int nx = x;
    int ny = y;
    board[nx][ny] = false;
    while (true) {
        nx++; ny++;
        if (nx < 0 || nx == boardSize || ny < 0 || ny == boardSize)
            break;
        board[nx][ny] = false;
    }
}

void func(int diagIndex = 0, int bishops = 0) {

    if (diagIndex == boardSize * 2 - 1) {
        if (bishops > maxBishops)
            maxBishops = bishops;
        return;
    }

    // printBoard();

    func(diagIndex + 1, bishops);

    bool boardCopy[10][10];
    FOR(i, boardSize) FOR(j, boardSize) boardCopy[i][j] = board[i][j];

    if (diagIndex < boardSize) {
        FOR(col, diagIndex + 1) {
            if (board[diagIndex - col][col]) {
                markBoard(diagIndex - col, col);
                func(diagIndex + 1, bishops + 1);
                FOR(i, boardSize) FOR(j, boardSize) board[i][j] = boardCopy[i][j];
            }
        }
    }
    else {
        for (int row = diagIndex; row > 0; row--) {
            if (board[row][diagIndex - row]) {
                markBoard(row, diagIndex - row);
                func(diagIndex + 1, bishops + 1);
                FOR(i, boardSize) FOR(j, boardSize) board[i][j] = boardCopy[i][j];
            }
        }
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> boardSize;

    FOR(i, boardSize) FOR(j, boardSize) cin >> board[i][j];

    // printBoard();

    func();
    // markBoard(1, 1);

    // printBoard();


    cout << maxBishops;

}