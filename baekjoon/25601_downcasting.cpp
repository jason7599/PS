#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> parents;

bool check(const string& A, const string& B) {
    string s = A;
    while (1) {
        if (s == B) {
            return 1;
        }
        if (parents.count(s)) {
            s = parents[s];
        } else {
            break;
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_classes;
    cin >> n_classes;

    for (int i = 0; i < n_classes - 1; i++) {
        string child, parent;
        cin >> child >> parent;
        parents[child] = parent;
    }

    string A, B;
    cin >> A >> B;

    cout << (check(A, B) || check(B, A)) << '\n';
}