#include <iostream>
#include <algorithm>

using namespace std;

int pieces[1'000'000];
int biggest[1'000]; // 한 col에 가장 큰 녀석
int placed[1'000]; // 한 col에 몇개 뒀는지 

int main()
{
    int numRows, numCols, numPieces;
    cin >> numRows >> numCols >> numPieces;

    for (int i = 0; i < numPieces; i++)
        cin >> pieces[i];

    sort(pieces, pieces + numPieces);

    int idx = 0;
    int ans = 0;

    while (idx < numPieces)
    {
        bool isDone = true;

        for (int col = 0; col < numCols; col++)
        {
            if (placed[col] == numRows) // 이미 다 함
                continue;
            
            isDone = false;

            if (biggest[col] < pieces[idx])
            {
                biggest[col] = pieces[idx];
                placed[col]++;
                ans++;
            }

            idx++; // 설치 안하는 경우에도, 이 piece는 그 다음 col들에도 못 낄 놈이니까 지나가야됨
        }

        if (isDone)
            break;
    }

    cout << ans;

    return 0;
}