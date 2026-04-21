#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    int ans = 1;
    char prev = str[0];
    for (size_t i = 1; i < str.length(); i++)
    {
        if (str[i] <= prev)
            ans++;
        prev = str[i];
    }
    std::cout << ans;
}