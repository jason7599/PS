#include <iostream>
#include <queue>

using namespace std;

int inDegree[32001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int problemCount, prereqCount;
    cin >> problemCount >> prereqCount;

    vector<int> nextProblems[32001];
    while (prereqCount--) {
        int first, second;
        cin >> first >> second;
        nextProblems[first].push_back(second);
        inDegree[second]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= problemCount; i++)
        if (!inDegree[i]) pq.push(-i);

    while (!pq.empty()) {
        int cur = -pq.top();
        cout << cur << ' ';
        pq.pop();
        for (int next : nextProblems[cur]) {
            if (!(--inDegree[next])) pq.push(-next);
        }
    }
}