#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string input;
    for (string t; getline(cin, t);) {
        input += t;
    }

    int sum = 0;
    for (size_t base = 0, t; base < input.length();) {
        t = input.find(',', base);
        if (t == -1) {
            t = input.length(); 
        }
        sum += stoi(input.substr(base, t - base));
        base = t + 1;
    }
    

    cout << sum << '\n';
}
