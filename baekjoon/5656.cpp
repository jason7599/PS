#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    for (int i = 1;; i++)
    {
        int lhs, rhs;
        std::string op;
        
        std::cin >> lhs >> op >> rhs;

        if (op == "E")
            break;

        bool is_true;

        if (op == ">")
            is_true = lhs > rhs;
        else if (op == ">=")
            is_true = lhs >= rhs;
        else if (op == "<")
            is_true = lhs < rhs;
        else if (op == "<=")
            is_true = lhs <= rhs;
        else if (op == "==")
            is_true = lhs == rhs;
        else if (op == "!=")
            is_true = lhs != rhs;
        
        std::cout << "Case " << i << ": "
            << (is_true ? "true" : "false") << '\n';
    }
}