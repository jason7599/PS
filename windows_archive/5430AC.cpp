#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> inputArray() {

    deque<int> res;

    int len, prev = 0; // 2자리 이상인 숫자들 이어붙일라고
    char temp;

    cin >> len >> temp; // ['

    if (!len) {
        cin >> temp; // ]
        return res;
    }

    while (len) {
        cin >> temp;
        if (temp == ',' || temp == ']') {
            res.push_back(prev);
            prev = 0;
            len--;
        }
        else prev = prev * 10 + temp - '0';
    }

    return res;
}

void executeCommand(deque<int> input, string command) {

    bool reverse = false;

    for (char c : command) {
        if (c == 'R') reverse = !reverse;
        else { // 'D'
            if (input.empty()) { cout << "error\n"; return; }
            if (reverse) input.pop_back();
            else input.pop_front();
        }
    }

    cout << '[';
    while (!input.empty()) {
        if (reverse) {
            cout << input.back();
            input.pop_back();
        }
        else {
            cout << input.front();
            input.pop_front();
        }
        if (!input.empty()) cout << ',';
    }
    cout << "]\n";

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int testCaseCount; cin >> testCaseCount;

    while (testCaseCount--) {

        string cmd; cin >> cmd;
        executeCommand(inputArray(), cmd);

    }

}