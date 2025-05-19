#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    const string TF[] = {"false", "true"};
    
    string lhs, rhs;
    cin >> lhs >> rhs;

    if (lhs == "null") {
        for (int i = 0; i < 2; i++) {
            cout << "NullPointerException\n";
        }
        return 0;
    } else if (rhs == "null") {
        for (int i = 0; i < 2; i++) {
            cout << TF[0] << '\n';
        }
        return 0;
    }

    bool b0, b1;
    if ((b0 = lhs == rhs)) {
        b1 = 1;
    } else {
        if ((b1 = lhs.length() == rhs.length())) {
            for (int i = 0; i < lhs.length(); i++) {
                if (tolower(lhs[i]) != tolower(rhs[i])) {
                    b1 = 0;
                    break;
                }
            }
        }
    }

    cout << TF[b0] << '\n' << TF[b1] << '\n'; 
}
