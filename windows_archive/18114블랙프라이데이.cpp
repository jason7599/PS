#include <iostream>
#include <algorithm>

using namespace std;

int num_elems;
int arr[5'000];

bool find(int val)
{
    int left = 0;
    int right = num_elems - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == val)
            return true;
        
        if (arr[mid] > val)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int target_sum;

    cin >> num_elems >> target_sum;

    for (int i = 0; i < num_elems; i++)
        cin >> arr[i];

    sort(arr, arr + num_elems);

    if (find(target_sum))
        goto good;
    
    for (int i = 0; i < num_elems; i++)
    {
        if (target_sum - arr[i] == arr[i])
            continue;
        
        if (find(target_sum - arr[i]))
            goto good;
    }
    
    for (int i = 0; i < num_elems - 1; i++)
    {
        for (int j = i + 1; j < num_elems; j++)
        {
            if (target_sum - arr[i] - arr[j] == arr[i]
            || target_sum - arr[i] - arr[j] == arr[j])
                continue;
            
            if (find(target_sum - arr[i] - arr[j]))
                goto good;
        }
    }

    cout << 0;
    return 0;

good:
    cout << 1;
    return 0;
}