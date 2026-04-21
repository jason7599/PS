#include <bits/stdc++.h>

using namespace std;

struct Term {
    int coeff;
    bool deg;

    string integrate() const {
        string res;
        int v = deg ? coeff / 2 : coeff;
        if (v < 0) res.push_back('-');
        if (abs(v) != 1) res += to_string(abs(v));
        return res + string(deg + 1, 'x');
    }
};

vector<Term> parse(const string& str) {
    size_t t = str.find('x');
    if (t == -1) { // constant
        bool neg = str.front() == '-';
        return {Term{
            stoi((neg ? str.substr(1) : str)) * (neg ? -1 : 1),
            0
        }};
    }
    vector<Term> res;
    bool neg = str.front() == '-';
    if (!t || (neg && t == 1)) {
        res.push_back(Term{(neg ? -1 : 1), 1});
    } else {
        res.push_back(Term{
            stoi(str.substr(neg, t)) * (neg ? -1 : 1),
            1
        });
    }
    if (t != str.length() - 1) {
        neg = str[++t] == '-';
        int v = stoi(str.substr(t + 1)) * (neg ? -1 : 1);
        if (v) {
            res.push_back(Term{
                v, 
                0
            });
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    if (str == "0") {
        cout << "W\n";
        return 0;
    }

    vector<Term> terms = parse(str);
    cout << terms.front().integrate();
    if (terms.size() > 1) {
        if (terms.back().coeff > 0) {
            cout << '+';
        }
        cout << terms.back().integrate();
    }
    cout << "+W\n";
}