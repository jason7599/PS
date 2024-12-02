#include <iostream>
#include <vector>

void print_postfix(const std::vector<char>& prefix, size_t& idx)
{
    char c = prefix.at(idx);

    if (c == '+' || c == '-')
    {
        print_postfix(prefix, ++idx);
        print_postfix(prefix, ++idx);
        std::cout << c << ' ';
    }
    else
        std::cout << c << ' ';
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    while (1)
    {
        std::vector<char> exprs;
        char c;
        while ((c = getchar()) != '\n')
        {
            if (c != ' ')
                exprs.push_back(c);
        }

        if (exprs.size() == 1 && exprs.front() == '0')
            break;
        
        size_t idx = 0; // dumb
        print_postfix(exprs, idx);
        std::cout << '\n';
    }
}
