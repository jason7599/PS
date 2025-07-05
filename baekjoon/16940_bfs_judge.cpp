#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n_nodes;
vector<int> edges[100'001];
bool vis[100'001];
bool exps[100'001];

bool f(const vector<int>& arr) {
    queue<int> q({arr.front()});
    vis[arr.front()] = 1;
    exps[arr.front()] = 1;
    for (int i = 1; i < n_nodes;) {
        for (int q_size = q.size(); q_size; q_size--) {
            int n = q.front();
            q.pop();

            for (int t : edges[n]) {
                if (!vis[t]) {
                    vis[t] = 1;
                    exps[t] = 1;
                    q.push(t);
                }
            }
        }
        for (int t = 0; t < q.size(); t++, i++) {
            if (!exps[arr[i]]) {
                return 0;
            }
            exps[arr[i]] = 0;
        }
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