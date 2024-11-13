#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string target, clipboard;
        std::cin >> target >> clipboard;

        int time = 0;
        size_t pos = 0;
        while (pos < target.length())
        {
            if (pos + clipboard.length() - 1 < target.length() 
                && target.substr(pos, clipboard.length()) == clipboard)
                pos += clipboard.length();
            else
                pos++;
            time++;
        }

        std::cout << time << '\n';
    }
}