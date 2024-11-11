#include <iostream>
#include <vector>

/**
 * 6: {1, 2, 3}
 * 7: {1, 2, 4}
 * 10: {1, }
 * 
 * EX 10
 * ans ABCDBCCDDD
 * 
 * str      len     next=idx
 * A        9 // * len = 10, put 1 => len = 9(10 - 1 - (1 - 1)), start = 2
 * AB       7 // * len = 9, put 2 => len = 7(9 - 1 - (2 - 1)), start = 3 ~ 4
 * * * start = 3 ~ 4
 * * *  start = 3: AB + ...
 * * *  start = 4: ABB + ...
 * ABC  // * len = 7, put 3 => len = 4(7 - 1 - (3 - 1)), start = 4 ~ 6
 * * * start = 4: ABC + ...
 * * * start = 6: ABCCC + ...
 * 
 * * next = start + 1 ~ curr_len + start + 1
 */

int seq_len;

void fuck(int start, int cur_len)
{
    static std::vector<int> vec;

    if (cur_len == seq_len)
    {
        for (int i : vec)
            std::cout << i << ' ';
        std::cout << '\n';

        return;
    }

    if (cur_len > seq_len)
        return;

    vec.push_back(start);

    for (int next = start + 1; next <= cur_len + start + 1; next++)
    {
        fuck(start, cur_len + start);
    }

    vec.pop_back();

}

int main()
{
    seq_len = 10;
    fuck(1, 1);
}