#include <iostream>
#include <algorithm>

using namespace std;

int N, A[100'000], ans = -1000;

int func(int i) {
    if (i == N) return 0;
    int res = A[i] + max(0, func(i + 1));
    ans = max(ans, res);
    return res;
}

int main() {
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    func(0);

    cout << ans;

}