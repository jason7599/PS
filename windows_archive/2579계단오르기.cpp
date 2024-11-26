/*
dp를 1차원 배열로 하니까 문제점: start만 같고 oneHopLeft가 달라도
메모만 되어있으면 같은걸 반환해버림. 그럼 이차원 배열을 써야겠구나
*/

#include <iostream>
#include <string>

using namespace std;

int stairCount, stairs[301], dp[301][2];

int func(int start, int oneHopLeft) {

    // memoed
    if (dp[start][oneHopLeft]) return dp[start][oneHopLeft];

    // finish
    if (start == stairCount) {
        dp[start][oneHopLeft] = stairs[start];
        return stairs[start];
    }

    int oneHop = -1, twoHop = -1;

    if (oneHopLeft) oneHop = func(start + 1, oneHopLeft - 1);
    if (start + 2 <= stairCount) twoHop = func(start + 2, 1);

    // dead end
    if (oneHop == -1 && twoHop == -1) return -1;

    int res = stairs[start] + (oneHop > twoHop ? oneHop : twoHop);

    dp[start][oneHopLeft] = res;

    return res;
}

int main() {

    cin >> stairCount;

    for (int i = 1; i <= stairCount; i++) cin >> stairs[i];

    cout << func(0, 2);

}
