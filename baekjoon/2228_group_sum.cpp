#include <bits/stdc++.h>

using namespace std;

int n_elems, elems[100];
int dp[100][51]; // dp[i][k]: i index까지 살폈을때, k 개 그룹일때 답

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_groups;
    cin >> n_elems >> n_groups;
    for (int i = 0; i < n_elems; i++) {
        cin >> elems[i];
    }

    
}