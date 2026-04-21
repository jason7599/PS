#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<string, vector<string>> children;
    string root;
    
    int n_members;
    cin >> n_members >> root;

    for (int i = 0; i < n_members - 1; i++) {
        string parent, child;
        char t;
        cin >> parent >> t >> child;
        children[parent].push_back(child);
    }

    int max_width = 0;
    queue<string> q({root});
    for (int q_size; (q_size = q.size());) {
        max_width = max(max_width, q_size);
        while (q_size--) {
            const string& parent = q.front();
            
            for (const string& child : children[parent]) {
                q.push(child);
            }
            
            q.pop();
        }
    }

    cout << max_width << '\n';
}