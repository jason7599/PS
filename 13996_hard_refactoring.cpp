#include <iostream>
#include <string>
#include <vector>

struct Condition
{
    enum {GREATER, LESS} type;
    int val;

    bool evaulate(int x) const
    {
        if (type == GREATER)
            return x >= val;
        
        return x <= val;
    }
};

std::vector<std::string> parse(const std::string& line)
{
    std::vector<std::string> parsed;

    size_t base = 0;
    size_t t;
    while ((t = line.find(' ', base)) != std::string::npos)
    {
        parsed.push_back(line.substr(base, t - base));
        base = t + 1;
    }
    parsed.push_back(line.substr(base));

    return parsed;
}

std::vector<Condition> parse_conditions_and(const std::string& line)
{
    std::vector<Condition> parsed;

    auto tokens = parse(line);
    size_t i = 0;
    while (i < tokens.size())
    {
        if (tokens[i] == ">=" || tokens[i] == "<=")
        {
            Condition condition;
            condition.type = tokens[i] == ">=" ? Condition::GREATER : Condition::LESS;
            condition.val = std::stoi(tokens[i + 1]);

            parsed.push_back(condition);

            i += 2;
        }
        else
            i++;
    }

    return parsed;
}

bool test_value(const std::vector<std::vector<Condition>>& conditions_or, int val)
{
    for (const auto& conditions_and : conditions_or)
    {
        bool good = 1;
        for (const auto& condition : conditions_and)
        {
            if (!condition.evaulate(val))
            {
                good = 0;
                break;
            }
        }
        if (good)
            return 1;
    }
    return 0;
}

const int X_MIN = -32768;
const int X_MAX = 32767;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::vector<std::vector<Condition>> conditions_or;

    while (!std::cin.eof())
    {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty())
            break;
        conditions_or.push_back(parse_conditions_and(line));
    }

    int range_l = X_MIN;
    bool prev_test_res = 0;

    std::vector<std::vector<Condition>> conditions_trimmed;

    for (int x = X_MIN; x <= X_MAX; x++)
    {
        if (test_value(conditions_or, x))
        {
            if (!prev_test_res)
            {
                range_l = x;
                prev_test_res = 1;
            }
        }
        else
        {
            if (prev_test_res)
            {
                std::vector<Condition> conditions;

                if (range_l != X_MIN)
                    conditions.push_back({Condition::GREATER, range_l});
                conditions.push_back({Condition::LESS, x - 1});

                conditions_trimmed.push_back(conditions);

                prev_test_res = 0;
            }
        }
    }

    if (prev_test_res && range_l != X_MIN)
        conditions_trimmed.push_back({{Condition::GREATER, range_l}});

    if (conditions_trimmed.empty())
        std::cout << (prev_test_res ? "true" : "false") << '\n';
    else
    {
        for (size_t i = 0; i < conditions_trimmed.size(); i++)
        {
            for (size_t j = 0; j < conditions_trimmed[i].size(); j++)
            {
                std::cout << "x ";
                std::cout << (conditions_trimmed[i][j].type == Condition::GREATER ? ">= " : "<= ");
                std::cout << conditions_trimmed[i][j].val << ' ';

                if (j != conditions_trimmed[i].size() - 1)
                    std::cout << "&& ";
            }
            if (i != conditions_trimmed.size() - 1)
                std::cout << "||";
            std::cout << '\n';
        }
    }
}