#include <bits/stdc++.h>

using namespace std;

struct Choice {
    char op;
    int val;

    int calc(int num) const {
        switch (op) {
            case '+': return num + val;
            case '-': return num - val;
            case '*': return num * val;
            case '/': return num / val;
        }
        return -1;
    }
};

struct Turn {
    Choice first;
    Choice second;

    int calc(int num) const {
        return max(first.calc(num), second.calc(num));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_turns;
    cin >> n_turns;
    vector<Turn> turns(n_turns);
    for (auto& [t0, t1] : turns) {
        cin >> t0.op >> t0.val
            >> t1.op >> t1.val;
    }

    int no_skip = 1, skip;
    for (Turn& turn : turns) {
        
    }
}