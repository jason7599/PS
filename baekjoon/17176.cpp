#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int code_len;
    std::cin >> code_len;

    std::string code;
    code.reserve(code_len);

    for (int i = 0; i < code_len; i++)
    {
        int v;
        std::cin >> v;

        if (!v)
            code.push_back(' ');
        else
            code.push_back(v + (v > 26 ? 'a' - 27 : 'A' - 1));
    }

    std::cin.ignore();

    std::string res;
    std::getline(std::cin, res);

    std::cout << code << '\n';
    std::cout << res << '\n';

    std::cout << (res == code ? 'y' : 'n');
}