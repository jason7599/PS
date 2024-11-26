#include <iostream>
#include <string>
#include <stack>

using namespace std;

string input, bomb;
stack<int> mstack;

void flush_stack()
{
    if (mstack.empty())
        return;
    
    int t = mstack.top();
    mstack.pop();

    flush_stack();

    for (int i = 0; i < t; i++)
        cout << bomb[i];
}

int main()
{
    bool frula = true;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> input >> bomb;

    for (char c : input)
    {
        if (c == bomb[0]) // start new streak
        {
            if (bomb.length() != 1)
                mstack.push(1);
        }
        else if (!mstack.empty() && c == bomb[mstack.top()]) // extend prev streak
        {
            if (++mstack.top() == bomb.length())
            {
                mstack.pop();
            }
        }
        else // flush prev streak if exists
        {
            flush_stack();

            cout << c;
            frula = false;
        }
    }

    if (!mstack.empty())
    {
        flush_stack();
        frula = false;
    }

    if (frula) cout << "FRULA";
}