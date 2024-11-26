#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int num_vals;
    int vals[26];

    cin >> num_vals;

    string str;
    cin >> str;

    for (int i = 0; i < num_vals; i++)
        cin >> vals[i];

    stack<double> st;

    for (char c : str)
    {
        if ('A' <= c && c <= 'Z')
            st.push(vals[c - 'A']);
        else
        {
            double v1 = st.top(); st.pop();
            double v0 = st.top(); st.pop();
            double v;
            switch (c)
            {
                case '+': v = v0 + v1; break;
                case '-': v = v0 - v1; break;
                case '*': v = v0 * v1; break;
                case '/': v = v0 / v1; break;
            }
            st.push(v);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}