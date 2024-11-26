#include <iostream>

using namespace std;

int N, A[2001];
bool DP[2001][2001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        DP[i][0] = true;
    }

}