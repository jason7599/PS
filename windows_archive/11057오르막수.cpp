#include <iostream>

#define DIV 10007

using namespace std;

// D[i][j]: i부터 시작하고 길이가 j인 오르막 수의 개수
int N, D[1001][11];

int func(int start, int len) {
    if (D[start][len]) return D[start][len];
    if (len == 1) {
        D[start][len] = 1;
        return 1;
    }
    int res = 0;
    for (int next = start; next < 10; next++)
        res += func(next, len - 1);
    D[start][len] = res % DIV;
    return D[start][len];
}

int main() {

    cin >> N;

    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans += func(i, N);
    cout << ans % DIV;

}