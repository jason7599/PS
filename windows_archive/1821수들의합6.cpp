#include <iostream>
#include <algorithm>

using namespace std;

int get_last(const int size, const int arr[])
{
    int sum[9];

    if (size == 1)
        return arr[0];

    for (int i = 0; i < size - 1; i++)
        sum[i] = arr[i] + arr[i + 1];
    
    for (int l = size - 2; l > 0; l--)
    {
        for (int i = 0; i < l; i++)
            sum[i] += sum[i + 1];
    }

    return sum[0];
}

int main()
{
    int size, last;
    cin >> size >> last;

    int arr[10];
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    
    do
    {
        if (get_last(size, arr) == last)
        {
            for (int i = 0; i < size; i++)
                cout << arr[i] << ' ';
            break;
        }
    } while (next_permutation(arr, arr + size));

    return 0;
}