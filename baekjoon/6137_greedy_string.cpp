#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len;
    cin >> len;

    string str;
    str.resize(len);

    for (char& c : str) {
        cin >> c;
    }
    
    string res;
    res.resize(len);

    int l = 0;
    int r = len - 1;
    int i = 0;

    while (i < len) {
        if (str[l] < str[r]) {
            res[i++] = str[l++];
        } else if (str[l] > str[r]) {
            res[i++] = str[r--];
        } else {
            int nl = l + 1;
            int nr = r - 1;

            while (nl < nr && str[nl] == str[nr]) {
                nl++;
                nr--;
            }

            if (str[nl] < str[nr]) {
                res[i++] = str[l++];
            } else {
                res[i++] = str[r--];
            }
        }
    }

    for (i = 0; i < len; i++) {
        cout << res[i];
        if ((i + 1) % 80 == 0) {
            cout << '\n';
        }
    }

    if (len % 80) {
        cout << '\n';
    }
}