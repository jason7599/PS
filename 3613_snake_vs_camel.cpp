#include <iostream>
#include <string>

using namespace std;

bool is_upper(char c)
{
    return 'A' <= c && c <= 'Z';
} 

char upper(char c)
{
    return c + 'A' - 'a';
}

char lower(char c)
{
    return c -'A' + 'a';
}

string convert(const string& str)
{
    if (str.front() == '_' || str.back() == '_' || is_upper(str.front()))
    {
error:
        return "Error!";
    }

    string res;

    const short undetermined = 0;
    const short cpp = 1;
    const short java = 2;

    short state = undetermined;

    bool cap = 0;
        
    for (char c : str)
    {
        if (c == '_')
        {
            if (state == java)
                goto error;
            
            state = cpp;

            if (cap)
                goto error;

            cap = 1;
        }
        else if (is_upper(c))
        {
            if (state == cpp)
                goto error;
            
            state = java;

            res += '_';
            res += lower(c);
        }
        else
        {
            if (state == cpp && cap)
            {
                res += upper(c);
                cap = 0;
            }
            else
                res += c;
        }
    }

    return res;
}

int main()
{
    string str;
    cin >> str;
    cout << convert(str);
    return 0;
}