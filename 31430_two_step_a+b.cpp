#include <iostream>
#include <string>

using namespace std;

string my_encode(long long val)
{
    string code;

    while (val)
    {
        code += val % 26 + 'a';
        val /= 26;
    }

    code += string(13 - code.length(), 'a');

    return code;
}

long long my_decode(const string& code)
{
    long long val = 0;
    long long d = 1;
    for (char c : code)
    {
        val += (c - 'a') * d;
        d *= 26;
    }
    return val;
}

int main()
{
    int mode;
    cin >> mode;
    if (mode == 1)
    {
        long long a, b;
        cin >> a >> b;
        cout << my_encode(a + b);
    }
    else
    {
        string code;
        cin >> code;
        cout << my_decode(code);
    }
    return 0;
}
