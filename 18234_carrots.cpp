#include <bits/stdc++.h>

using namespace std;

struct Carrot {
    int init_val;
    int add_val;
};

int n_carrots;
Carrot carrots[200'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_days;
    cin >> n_carrots >> n_days;

    for (int i = 0; i < n_carrots; i++)
        cin >> carrots[i].init_val >> carrots[i].add_val;

    
}