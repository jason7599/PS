#include <iostream>

using namespace std;

int main()
{
    int len;
    cin >> len;

    uint64_t c_cnt = 0;
    uint64_t co_cnt = 0;
    uint64_t cow_cnt = 0;

    for (int i = 0; i < len; i++)
    {
        char c;
        cin >> c;
        if (c == 'C')
            c_cnt++;
        else if (c == 'O')
            co_cnt += c_cnt;
        else
            cow_cnt += co_cnt;
    }

    cout << cow_cnt;

    return 0;
}