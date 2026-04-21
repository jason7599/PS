#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, k;
int M[10][10];
int ans = INT_MIN;

void fuck() {
    static int K[10];
    static int ki;
    static int ni;

    if (ki == k) {
        int sum = 0;
        for (int i = 0; i < k - 1; i++) {
            for (int j = i + 1; j < k; j++) {
                sum += M[K[i]][K[j]];
            }
        }
        ans = max(ans, sum);
        return;
    }

    K[ki++] = ni++;
    fuck();

    ki--, ni--;

    if (k - ki < n - ni) {
        ni++;
        fuck();
        ni--;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    fuck();

    cout << ans << '\n';
}
