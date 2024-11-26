#include <iostream>
#include <string>

using namespace std;

int numCount, mode, k, it;
bool visited[21];
string target;

void func(int length = 0, string res = "") {

    if (length == numCount) {
        it++;
        if (mode == 1 && it == k)
            cout << res;
        else if (mode == 2 && res == target)
            cout << it;
        return;
    }

    for (int i = 1; i <= numCount; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        func(length + 1, res + to_string(i) + ' ');
        visited[i] = false;
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> numCount;
    cin >> mode;
    if (mode == 1) cin >> k;
    else {
        getline(cin, target);
        target += ' ';
        target.erase(0, 1);
    }

    func();

}