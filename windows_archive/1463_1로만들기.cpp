/*
시간 제한 0.15초인걸 보면 dp를 쓰는게 맞는거같음.
N은 최대 백만이고 메모리 제한은 128MB라서 될까 싶었는데
1MB이 백만 바이트니까, int 백만개짜리 배열이면 4MB정도하겠네.
1MB이 백만 바이트라는거 기억하고, 앞으로도 대충 계산해보자
*/

#include <iostream>

using namespace std;

int x, dp[1'000'001];

int func(int n) {
    // 0이 아님: 이미 계산(memo)됨
    // 다만 dp[1]은 0이 맞음
    if (dp[n] || n == 1) return dp[n];

    int res = 987654321;
    int temp;

    if (!(n % 3)) res = func(n / 3);
    if (!(n % 2)) {
        temp = func(n / 2);
        if (res > temp) res = temp;
    }
    temp = func(n - 1);
    if (res > temp) res = temp;

    dp[n] = ++res;
    return res;
}

int main() {

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    cin >> x;

    cout << func(x);
}