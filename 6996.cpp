#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        std::string a, b;
        std::cin >> a >> b;

        std::cout << a << " & " << b << " are ";

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        if (a != b)
            std::cout << "NOT ";
        std::cout << "anagrams.\n";
    }
}