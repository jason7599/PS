#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int num_brackets;
int r_bracket_id[10];

int equation_len;
char equation[200];

vector<string> comb;

void func(int bracket_idx = 0)
{
    static bool print_bracket_id[10] = {0};
    static bool first_dumbass = true;

    if (bracket_idx == num_brackets)
    {
        if (first_dumbass)
        {
            first_dumbass = false;
            return;
        }

        string s;
        int l = 0, r = 0;
        for (int ci = 0; ci < equation_len; ci++)
        {
            if (equation[ci] == '(')
            {   
                if (print_bracket_id[l++])
                    s += '(';
            }
            else if (equation[ci] == ')')
            {
                if (print_bracket_id[r_bracket_id[r++]])
                   s += ')';
            }
            else
                s += equation[ci];
        }

        comb.push_back(s);
        return;
    }

    print_bracket_id[bracket_idx] = true;
    func(bracket_idx + 1);
    print_bracket_id[bracket_idx] = false;

    func(bracket_idx + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    char c;
    stack<int> l_bracket_stk;
    int r_bracket_cnt = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c == '(')
            l_bracket_stk.push(num_brackets++);
        else if (c == ')')
        {
            r_bracket_id[r_bracket_cnt++] = l_bracket_stk.top();
            l_bracket_stk.pop();
        }
        equation[equation_len++] = c;
    }

    func();

    sort(comb.begin(), comb.end());
    string prev;
    for (string s : comb)
    {
        if (s == prev)
            continue;
        
        cout << s << '\n';
        prev = s;
    }
}