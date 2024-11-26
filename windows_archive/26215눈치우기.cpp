#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n; cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    int time = 0;
    
    while (!pq.empty()) {

        int top = pq.top(); pq.pop();

        if (pq.empty()) {
            time += top;
            break;
        }

        int next = pq.top(); pq.pop();

        if (--top) pq.push(top);
        if (--next) pq.push(next);

        time++;
    }

    if (time < 1441) cout << time;
    else cout << -1;

}