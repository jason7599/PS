#include <bits/stdc++.h>
using namespace std;

bool is_acronym(const string& acr, const string& str) {
    for (size_t acr_i = 0, str_i = 0;;) {
        if (acr[acr_i++] != str[str_i]) {
            return 0;
        }
        str_i = str.find(' ', str_i);
        if (str_i++ == -1) {
            return acr_i == acr.length();
        }
    }
    assert(0);
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        string acr;
        int n_strs;
        cin >> acr >> n_strs;
        cout << acr << '\n';
        cin.ignore();
        while (n_strs--) {
            string str;
            getline(cin, str);
            if (is_acronym(acr, str)) {
                cout << str << '\n';
            }
        }
    }
}