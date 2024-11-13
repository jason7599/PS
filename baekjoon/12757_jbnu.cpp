#include <iostream>
#include <vector>
#include <algorithm>

struct Record
{
    int key;
    int value;
};

int key_margin;
std::vector<Record> jbnu;

void insert(Record record)
{
    size_t pos = std::upper_bound(jbnu.begin(), jbnu.end(), record) - jbnu.begin();
    jbnu.insert(jbnu.begin() + pos, record);
}

size_t find(int val)
{
    return std::lower_bound(jbnu.begin(), jbnu.end(), val) - jbnu.begin();
}

int main()
{
    int init_data_cnt, num_queries;
    std::cin >> init_data_cnt >> num_queries >> key_margin;

    jbnu.reserve(init_data_cnt);

    for (int i = 0; i < init_data_cnt; i++)
    {
        int x;
        std::cin >> x;
        insert(x);
    }

    while (num_queries--)
    {
        int op, key;
        std::cin >> op >> key;

        if (op == 1)
        {
            int val;
            std::cin >> val;
            insert(val);
        }
        else if (op == 2)
        {
            int val;
            std::cin >> val;

            size_t pos = find(key);
            if (pos != jbnu.size() && jbnu[pos] == )
        }
    }
}