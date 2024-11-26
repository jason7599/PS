#include <iostream>

using namespace std;

int N, M, memo[1'000'000], ans;
char S[1'000'000];

int func(int index = 0)
{
    if (index >= M) return 0;
    
    int& res = memo[index];

    if (res != -1) 
    {
        return res;
    }

    if (index >= M - 2) return res = 0;
    
    if (S[index] == 'O') return res = 0;

    if (S[index + 1] == 'O' && S[index + 2] == 'I')
    {
        res = 1 + func(index + 2);
    }
    else
    {
        res = 0;
    }
    
    if (res >= N) ans++;

    return res;

}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> S[i];
        memo[i] = -1;
    }
    
    for (int i = 0; i < M; i++)
        func(i);

    cout << ans << '\n';

}