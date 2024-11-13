#include <iostream>
#include <string>
#include <stack>
#include <map>

const std::map<char, char> op_brackets = {
    {')', '('},
    {'}', '{'},
    {']', '['}
};

bool is_legal(const std::string& line)
{
    std::stack<char> st;

    for (char c : line)
    {
        switch (c)
        {
        case '(':
        case '{':
        case '[':
            st.push(c);
            break;
        
        case ')':
        case '}':
        case ']':
            if (st.empty() || st.top() != op_brackets.at(c))
                return 0;
            st.pop();
        default:
            break;
        }
    }

    return st.empty();
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    while (1)
    {
        std::string line;
        std::getline(std::cin, line);

        if (line == "#")
            break;
        
        if (is_legal(line))
            std::cout << "Legal\n";
        else
            std::cout << "Illegal\n";
    }
}