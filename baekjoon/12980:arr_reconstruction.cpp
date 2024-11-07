#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int arr_len;
int arr[100];

int get_score(const vector<int>& num_pool)
{
    int score = 0;
    int pool_num_idx = 0;

    for (int i = 0; i < arr_len - 1; i++)
    {
        int lv;
        if (arr[i]) lv = arr[i];
        else lv = num_pool[pool_num_idx++];

        int t_idx = pool_num_idx;
        for (int j = i; j < arr_len; j++)
        {
            int rv;
            if (arr[j]) rv = arr[j];
            else rv = num_pool[t_idx++];

            if (lv < rv)
                score++;
        }
    }

    return score;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int score;
    cin >> arr_len >> score;

    set<int> appeared;
    for (int i = 0; i < arr_len; i++)
    {
        cin >> arr[i];
        if (arr[i])
            appeared.insert(arr[i]);
    }

    vector<int> num_pool;
    for (int num = 1; num <= arr_len; num++)
    {
        if (appeared.find(num) == appeared.end())
            num_pool.push_back(num);
    }

    int ans = 0;
    do
    {
        if (get_score(num_pool) == score)
            ans++;
    } while (next_permutation(num_pool.begin(), num_pool.end()));

    cout << ans;
    return 0;
}