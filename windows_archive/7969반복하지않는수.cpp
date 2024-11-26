#include <iostream>

using namespace std;

int nums[1'000'001];
int last_index;

bool check(int num)
{
    bool v[10] = {false};

    while (num)
    {
        int x = num % 10;
        if (v[x])
            return false;
        v[x] = true;
        num /= 10;
    }

    return true;
}

int get(int index)
{
    if (nums[index])
        return nums[index];
    
    int last_num = nums[last_index];

    while (last_index < index)
    {
        while (!check(++last_num));
        nums[++last_index] = last_num;
    }

    return nums[index];
}

int main()
{
    int i;
    while (true)
    {
        cin >> i;
        if (i == 0)
            break;
        cout << get(i) << '\n';
    }
    return 0;
}