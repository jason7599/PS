#include <iostream>

#define INF 987654321

using namespace std;

typedef int (*op) (int x, int y);

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int dlv(int x, int y) { return x / y; }

int numCount, nums[11], operatorCount[4];
int _max = -INF, _min = INF;
op operators[] = { add, sub, mul, dlv };

void combine(int curNum, int index = 0)
{
    if (++index == numCount)
    {
        if (curNum > _max)
            _max = curNum;

        if (curNum < _min)
            _min = curNum;
        
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operatorCount[i])
        {
            operatorCount[i]--;
            combine(operators[i](curNum, nums[index]), index);
            operatorCount[i]++;
        }
    }
}

int main()
{
    cin >> numCount;

    for (int i = 0; i < numCount; i++)
        cin >> nums[i];

    for (int i = 0; i < 4; i++)
        cin >> operatorCount[i];

    combine(nums[0]);

    cout << _max << '\n' << _min;
}