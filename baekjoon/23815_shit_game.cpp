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
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_turns;
    cin >> n_turns;
    vector<Turn> turns(n_turns);
    for (auto& [c0, c1] : turns) {
        cin >> c0.op >> c0.val
            >> c1.op >> c1.val;
    }

    vector<array<int, 2>> dp(n_turns);

}