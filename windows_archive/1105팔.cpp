#include <iostream>

using namespace std;

int count_eights(int num)
{
    int count = 0;
    while (num)
    {
        if (num % 10 == 8) count++;
        num /= 10;
    }
    return count;
}

int main()
{
    int start, end;
    cin >> start >> end;

    int min_eights = 10;
    for (int i = start; i <= end; i++)
    {
        int eights = count_eights(i);
        if (eights < min_eights)
            min_eights = eights;
    }
    cout << min_eights;
}