#include <iostream>
#include <string>

int main()
{
    int seq_len;
    std::cin >> seq_len;

    int cnt[53] = {0};
    int nz = 0;
    for (int i = 0; i < seq_len; i++)
    {
        int code;
        std::cin >> code;
        if (!cnt[code]++)
            nz++;
    }

    std::string str;
    std::cin.ignore();
    std::getline(std::cin, str);

    bool good = 1;
    for (char c : str)
    {
        int code;
        if (c == ' ')
            code = 0;
        else if ('A' <= c && c <= 'Z')
            code = c - 'A' + 1;
        else
            code = c - 'a' + 27;
        
        if (!cnt[code])
        {
            good = 0;
            break;
        }

        if (!--cnt[code])
            nz--;
    }

    good &= !nz;

    std::cout << (good ? 'y' : 'n');
}