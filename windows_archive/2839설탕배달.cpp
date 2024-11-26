#include <iostream>

using namespace std;

int weight;
int dp[5001];

// memo 쓰자
int func(int weightLeft) {

    if (weightLeft < 3) return -1; //불가능

    int res = dp[weightLeft];

    if (res) return res; //메모됨

    int bag3 = func(weightLeft - 3);
    int bag5 = func(weightLeft - 5);

    // 둘다 불가능
    if (bag3 == -1 && bag5 == -1) res = -1;
    else {
        if (bag3 == -1) res = bag5;
        else if (bag5 == -1) res = bag3;
        else res = bag3 < bag5 ? bag3 : bag5;
        res++; // 3이든 5든 하나 챙겼으니
    }

    dp[weightLeft] = res;
    return res;
}

int main() {

    dp[3] = dp[5] = 1;

    cin >> weight;

    cout << func(weight);

}