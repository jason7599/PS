#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[10'000];

long long fuck(int i)
{
    int x = -arr[i]; // 찾고자 하는 sum
    int l = i + 1;
    int r = n - 1;

    int ans = 0;

    while (l < r)
    {
        int l_val = arr[l];
        int r_val = arr[r];
        int sum = l_val + r_val;

        if (sum == x) // 찾았다! 근데 다른 문제와 달리, 찾았음만을 따지는게 아니라, 개수를 세야돼.
        {

            if (l_val == r_val)
            {
                ans += r - l; 
                l++;
                /**
                 * 예를 들어 
                 * 1, 1, 1, 1, 1
                 * l           r
                 * 이고 2를 만들고 싶은 상황.
                 * l = 0 이고 r = 4라고 하자.
                 * 
                 * l = 0으로 고정시킨다고 치면,
                 * r이 될 수 있는 건 1, 2, 3, 4, 5 잖아.
                 */

            }
            else
            {
                // 중복을 세줘야 하니까. 예를 들어
                /* 1, 1, 2, 3, 3
                * l           r
                *
                * x = -4
                * 
                * 2 * 2
                * 
                * ㅁㄴㅁㄴㅁ
                */

                int l_cnt = 1;
                int r_cnt = 1;

                while (arr[++l] == l_val)
                    l_cnt++;
                
                while (arr[--r] == r_val)
                    r_cnt++;

                ans += l_cnt * r_cnt;
            }
        }
        else if (sum < x)
            l+
        else
            r--;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long long ans = 0;

    for (int i = 0; i < n - 2; i++)
        ans += fuck(i);

    cout << ans;

    return 0;
}