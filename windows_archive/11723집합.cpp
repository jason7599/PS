#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int bits = 0;
    int m; cin >> m;

    while (m--) {
        string cmd; cin >> cmd;
        if (cmd == "all") bits = (1 << 20) - 1;
        else if (cmd == "empty") bits = 0;
        else {
            int num; cin >> num; num--;
            if (cmd == "add") bits |= (1 << num);
            else if (cmd == "remove") bits &= ~(1 << num);
            else if (cmd == "check") cout << ((bits >> num) & 1) << '\n';
            else if (cmd == "toggle") bits ^= (1 << num);
        }
    }

}