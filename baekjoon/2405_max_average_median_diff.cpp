#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> arr;

int fuck(int v, int l, int r) {
    return max(
        abs(v - arr[l]),
        abs(v - arr[r])
    );
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    arr.resize(n);
    for (int& i : arr) {
        cin >> i;
    }

    /**
     * |(a + c) - 2b|
     * = |(a - b) + (c - b)|
     * = |(c - b) - (b - a)| -> a랑 b의 거리 vs b랑 c의 거리 최대화
     * 따라서 b는 a 바로 다음 숫자이거나 c 바로 이전의 숫자여야 함
     * 
     * 그럼 b를 하나 잡으면 a나 c 적어도 하나는 고정시킬 수 있음
     * 예를 들어 b를 고정하고 a는 b 바로 전의 숫자라고 가정한다면
     * |a - 2b + c|를 계산하는 건데, a - 2b는 이미 아는 값이 되고
     * |c - (2b - a)|로 생각하면 c를 그냥 2b - a랑 가장 차이가 큰 값으로 잡으면 되겠음
     * 
     * c가 b 바로 다음이라고 가정하면
     * |c - 2b + a| = |a - (2b - c)|
     */

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int b = 1; b < n - 1; b++) {
        ans = max(ans,
            max(
                fuck(2 * arr[b] - arr[b - 1], b + 1, n - 1),    // a는 b 바로 전
                fuck(2 * arr[b] - arr[b + 1], 0, b - 1)         // c는 b 바로 다음
            )
        );
    }
    cout << ans << '\n';
}
