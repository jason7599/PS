#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 80;

vector<string> parse(const string& text) {
    vector<string> res;
    size_t base = text.find_first_not_of(' ');
    for (size_t t; base < text.length();) {
        t = text.find(' ', base);
        if (t == -1) {
            t = text.length();
        }
        res.push_back(text.substr(base, t - base));
        base = text.find_first_not_of(' ', t + 1);
    }

    return res;
}

void print_html(const vector<string>& html) {
    string line;
    for (const string& s : html) {
        if (s == "<hr>") {
            if (!line.empty()) {
                cout << line << '\n';
                line.clear();
            }
            cout << string(MAX_LEN, '-') << '\n';
        } else if (s == "<br>") {
            cout << line << '\n';
            line.clear();
        } else {
            if (line.length() + 1 + s.length() > MAX_LEN) {
                cout << line << '\n';
                line.clear();
            }
            if (!line.empty()) {
                line.push_back(' ');
            }
            line += s;
        }
    }
    if (!line.empty()) {
        cout << line << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string text;
    for (string t; getline(cin, t);) {
        text += t;
        if (t.back() != ' ') {
            text.push_back(' ');
        }
    }

    print_html(parse(text));
}