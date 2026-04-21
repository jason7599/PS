#include <iostream>
#include <string>

int main()
{
    std::string start, end;
    std::cin >> start >> end;

    int ans = 0;
    if (start.length() == end.length())
    {
        for (size_t i = 0; i < start.length(); i++)
        {
            if (start[i] == end[i])
            {
                if (start[i] == '8')
                    ans++;
            }
            else
                break;
        }
    }

    std::cout << ans;
}