#include <iostream>

using namespace std;

int main()
{
    int temps[100'000];
    int days, window_size;
    int sum = 0, highest_sum;
    int i, x;

    cin >> days >> window_size;

    for (i = 0; i < window_size; i++)
    {
        cin >> x;
        temps[i] = x;
        sum += x;
    }
    highest_sum = sum;

    for (; i < days; i++)
    {
        cin >> x;
        temps[i] = x;
        sum += x - temps[i - window_size];
        if (sum > highest_sum)
            highest_sum = sum;
    }

    cout << highest_sum;
    
}