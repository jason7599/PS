#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int> maxQ;

    int t; cin >> t;
    maxQ.push(t);
    cout << t << '\n';

    for (int i = 1; i < n; i++) {
        cin >> t;
        if (i % 2) { // insert in minQ
            if (maxQ.top() > t) {
                minQ.push(maxQ.top());
                maxQ.pop();
                maxQ.push(t);
            }
            else minQ.push(t);
        }
        else { // in maxQ
            if (minQ.top() < t) {
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(t);
            }
            else maxQ.push(t);
        }
        cout << maxQ.top() << '\n';
    }

}