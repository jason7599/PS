#include <iostream>
#include <queue>

using namespace std;

int main() {

    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--) {
        int n, m;
        cin >> n >> m;

        priority_queue<int> priority;
        queue<pair<int, int>> order;

        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            priority.push(p);
            order.push({ i, p });
        }

        int ans = 0;
        while (true) {
            if (order.front().second < priority.top()) {
                pair<int, int> temp = order.front();
                order.pop();
                order.push(temp);
            }
            else {
                ans++;
                if (order.front().first == m) {
                    cout << ans << '\n';
                    break;
                }
                order.pop();
                priority.pop();
            }
        }


    }

}