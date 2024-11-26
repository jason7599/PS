#include <iostream>

using namespace std;

int n, white, blue;
bool paper[128][128];

void func(int x, int y, int len) {
    int b = 0;
    for (int nx = x; nx < x + len; nx++)
        for (int ny = y; ny < y + len; ny++)
            if (paper[nx][ny]) b++;
    if (!b) white++;
    else if (b == len * len) blue++;
    else {
        func(x, y, len / 2);
        func(x, y + len / 2, len / 2);
        func(x + len / 2, y, len / 2);
        func(x + len / 2, y + len / 2, len / 2);
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];

    func(0, 0, n);

    cout << white << '\n' << blue;

}