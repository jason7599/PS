#include <iostream>

using namespace std;

int length;
int res;
int numerals[] = {1, 5, 10, 50};
bool visited[1001];

void combine(int index = 0, int start = 0, int sum = 0)
{
    if (index++ == length)
    {
        if (!visited[sum])
        {
            visited[sum] = true;
            res++;
        }
        return;
    }

    for (int i = start; i < 4; i++)
    {
        combine(index, i, sum + numerals[i]);
    }
}

int main()
{
    cin >> length;
    combine();
    cout << res;
}