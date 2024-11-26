#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    while (true) {
        string line;
        getline(cin, line);
        if (line == ".") return 0;
        stack<bool> s; // ( true [ false
        bool fucked = false;
        for (char c : line) {
            if (c == '(') s.push(true);
            else if (c == '[') s.push(false);
            else if (c == ')') {
                if (s.empty() || !s.top()) {
                    fucked = true;
                    break;
                }
                s.pop();
            }
            else if (c == ']') {
                if (s.empty() || s.top()) {
                    fucked = true;
                    break;
                }
                s.pop();
            }
        }
        if (!fucked && s.empty()) cout << "yes\n";
        else cout << "no\n";
    }

}