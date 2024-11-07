#include <iostream>
#include <string>

using namespace std;

string add(const string&, const string&);
string mult_single_digit(const string&, const char);
string mult(const string&, const string&);
string subtract(const string&, const string&);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string lhs, rhs;
    char op;

    cin >> lhs >> op >> rhs;

    string res;
    switch (op)
    {
        case '+':
        res = add(lhs, rhs);
        break;

        case '*':
        res = mult(lhs, rhs);
        break;

        case '-':
        res = subtract(lhs, rhs);
        break;

        default:
        res = "invalid op";
        break;
    }

    cout << res;
    return 0;
}

string add(const string& lhs, const string& rhs)
{
    string res;

    bool carry = 0;
    int l = lhs.length() - 1;
    int r = rhs.length() - 1;
    while (0 <= l || 0 <= r)
    {
        int lv = l >= 0 ? lhs[l--] - '0' : 0;
        int rv = r >= 0 ? rhs[r--] - '0' : 0;

        int v = lv + rv + carry;

        res.insert(0, 1, v % 10 + '0');
        carry = v >= 10;
    }

    if (carry)
        res.insert(0, 1, '1');

    return res;
}

string mult_single_digit(const string& lhs, const char rhs)
{
    string res;
    int rv = rhs - '0';

    int carry = 0;
    for (int i = lhs.length() - 1; i >= 0; i--)
    {
        int v = rv * (lhs[i] - '0') + carry;
        res.insert(0, 1, v % 10 + '0');
        carry = v / 10; 
    }

    if (carry)
        res.insert(0, 1, carry + '0');

    return res;
}

string mult(const string& lhs, const string& rhs)
{
    string res = "0";

    for (int i = 0; i < rhs.length(); i++)
    {
        string v = mult_single_digit(lhs, rhs[rhs.length() - 1 - i])
            .append(i, '0');
        res = add(res, v);
    }

    return res;
}

string subtract(const string& lhs, const string& rhs)
{
    string res;

    

    return res;
}
