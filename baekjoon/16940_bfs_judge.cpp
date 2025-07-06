#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n_nodes;
vector<int> edges[100'001];
bool vis[100'001];

bool f(const vector<int>& arr) {
    if (arr.front() != 1) {
        return 0;
    }

    queue<int> q({1});
    queue<unordered_set<int>> nexts;
    nexts.push({1});
    vis[1] = 1;

    int i = 0, w = 1;
    while (i < n_nodes) {
        int nx_w = 0;
        int sub_w = 0;
        for (; w; w--, i++) {
            int n = arr[i];
            if (nexts.front().count(n) == 0) {
                return 0;
            }
            if (++sub_w == nexts.front().size()) {
                nexts.pop();
                sub_w = 0;
            }

            unordered_set<int> next;
            for (int t : edges[n]) {
                if (!vis[t]) {
                    vis[t] = 1;
                    q.push(t);
                    next.insert(t);
                    nx_w++;
                }
            }
            if (next.size()) {
                nexts.push(next);
            }
        }
        w = nx_w;
    }

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n_nodes;
    for (int i = 0; i < n_nodes - 1; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    vector<int> arr(n_nodes);
    for (int& i : arr) {
        cin >> i;
    }

    cout << f(arr) << '\n';
}