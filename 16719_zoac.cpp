#include <bits/stdc++.h>
using namespace std;

void func(string& str, int l, int r, string& path) {
    if (l == r) {
        return;
    }

    char min_char = 'Z';
    int min_char_idx;
    for (int i = l; i <= r; i++) {
        if (str[i] < min_char) {
            min_char = str[i];
            min_char_idx = i;
        }
    }


}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;
    
}