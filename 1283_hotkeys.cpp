#include <iostream>
#include <string>

inline int ctoi(char c)
{
    if (c <= 'Z')
        return c - 'A';
    return c - 'a';
}

int main()
{
    int num_commands;
    std::cin >> num_commands;
    std::cin.ignore();

    bool alphabet_used[26] = {0};

    while (num_commands--)
    {
        std::string line;
        std::getline(std::cin, line);

        bool first_letter = 1;
        int pos = 0;
        int ans_pos = -1;

        while (pos < line.length())
        {
            char c = line[pos];

            if (c == ' ')
            {
                first_letter = 1;
                pos++;
                continue;
            }

            int cidx = ctoi(c);

            if (first_letter)
            {
                if (!alphabet_used[cidx])
                {
                    ans_pos = pos;
                    break;
                }
                first_letter = 0;
            }
            else
            {
                if (ans_pos == -1 && !alphabet_used[cidx])
                    ans_pos = pos;
            }

            pos++;
        }

        if (ans_pos != -1)
        {
            alphabet_used[ctoi(line[ans_pos])] = 1;
            line.insert(ans_pos, 1, '[');
            line.insert(ans_pos + 2, 1, ']');
        }
        std::cout << line << '\n';
    }
}