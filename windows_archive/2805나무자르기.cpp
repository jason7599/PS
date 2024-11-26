#include <iostream>
#include <algorithm>

using namespace std;

int numTrees;
int trees[1'000'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int target;
    cin >> numTrees >> target;

    for (int i = 0; i < numTrees; i++)
        cin >> trees[i];

    // 정렬의 이점: while 문에서 break 가능
    sort(trees, trees + numTrees);

    // index가 아니고 자를 높이다
    int l = 0;
    int r = trees[numTrees - 1];
    int ans;

    while (l <= r)
    {
        // mid; 사실상 height
        int mid = (l + r) / 2;
        uint64_t sum = 0;

        // 역순으로
        for (int i = numTrees - 1; i >= 0; i--)
        {
            if (trees[i] <= mid) // 자를 수 없음; 이럴 경우 정렬되어있는 덕분에 후에 나올 tree들도 마찬가지.
                break;

            sum += trees[i] - mid;
        }

        // cout << "Height: " << mid << ": " << sum << '\n';

        // 조건 만족, 이럴 경우 더 높은 height도 따져봐야지
        if (sum >= target)
        {
            ans = mid;
            l = mid + 1;
        } 
        else // 안되는 경우, 더 작은 키 따져봐야지
            r = mid - 1;
    }

    cout << ans;

    return 0;
}