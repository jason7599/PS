#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nodeCount, cost[1000], dp[1000];
vector<int> pre[1000];

int func(int nodeIndex) {
    if (dp[nodeIndex] != -1) return dp[nodeIndex];
    int res = 0;
    for (int node : pre[nodeIndex]) res = max(res, func(node));
    return dp[nodeIndex] = res + cost[nodeIndex];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--) {
        int edgeCount;
        cin >> nodeCount >> edgeCount;

        for (int i = 0; i < nodeCount; i++) {
            cin >> cost[i];
            dp[i] = -1;
        }

        while (edgeCount--) {
            int first, second;
            cin >> first >> second;
            pre[second - 1].push_back(first - 1);
        }

        int goal; cin >> goal;

        cout << func(goal - 1) << '\n';

        if (testCaseCount) while (nodeCount--) pre[nodeCount].clear();
    }

}