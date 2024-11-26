#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int main() {

    // ㅅㅂ

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, H[100'000], temp, stuff1 = INF, stuff2 = -INF, stuff3 = 0, res;

    cin >> N >> H[0];
    for (int i = 1; i < N - 1; i++) {
        cin >> temp;
        H[i] = H[i - 1] + temp;
        stuff1 = min(stuff1, H[i] + temp);
        stuff2 = max(stuff2, H[i - 1] - temp);
        stuff3 = max(stuff3, temp);
    }
    cin >> temp;
    H[N - 1] = H[N - 2] + temp;

    res = 2 * H[N - 1] - H[0] - stuff1;
    res = max(res, H[N - 2] + stuff2);
    res = max(res, stuff3 + H[N - 2] - H[0]);

    cout << res;

}