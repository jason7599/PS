#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;

    stack<int> st;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        char c = str[i];
        if (c == 'x')
            st.push(0);
        else if (c == 'g')
        {
            if (st.empty())
                goto bad;

            int t = st.top();
            st.pop();
            st.push(t + 1);
        }
        else if (c == 'f')
        {
            if (st.size() < 2)
                goto bad;
            
            int t0 = st.top(); st.pop();
            int t1 = st.top(); st.pop();
            st.push(min(t0, t1));
        }
    }

    if (st.size() != 1)
        goto bad;

    cout << st.top();
    return 0;

bad:
    cout << -1;
    return 0;
}