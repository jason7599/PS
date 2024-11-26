#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1)
    {
        string line;
        getline(cin, line);

        if (line == "#")
            break;
        
        stack<string> tags;
        string tag;

        bool tag_flag = false;
        bool tag_complete = false;

        char last_c;

        for (char c : line)
        {
            if (c == '<')
            {
                tag_flag = true;
                continue;
            }
            
            if (tag_flag)
            {
                if (c == ' ')
                {
                    tag_complete = true;
                    continue;
                }

                // if (tag_complete)
            }
        }
    }

    return 0;
}