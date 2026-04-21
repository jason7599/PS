#include <iostream>
#include <algorithm>

struct Domino
{
    int pos;
    int height;
    int range_r; // 자신이 오른쪽으로 넘어질때 조질 수 있는 거리
    int range_l; // 자신을 왼쪽으로 넘어뜨릴 수 있는 최대 거리
};

int num_dominos;
Domino dominos[300];

bool can_reach(int d, int n)
{
    return std::abs(dominos[d].pos - dominos[n].pos) <= dominos[d].height;
}

void map_ranges(int d_idx = 0)
{
    Domino& domino = dominos[d_idx];

    if (d_idx == num_dominos - 1)
    {
        domino.range_r = 0;
        domino.range_l = 0;
        return;
    }

    map_ranges(d_idx + 1);

    domino.range_r = can_reach(d_idx, d_idx + 1) ?
        1 + dominos[d_idx + 1].range_r : 0;
    
    domino.range_l = can_reach(d_idx + 1, d_idx) ?
        1 + dominos[d_idx + 1].range_l : 0;
}

int solve(int d_idx = 0)
{
    static int memo[300];

    if (d_idx == num_dominos)
        return 0;
    
    if (memo[d_idx])
        return std::max(memo[d_idx], 0);

    const Domino& domino = dominos[d_idx];

    // 자신이 오른쪽으로 넘어지는 케이스
    int res = 1 + solve(d_idx + domino.range_r + 1);

    // 뒤에 놈이 나를 넘어뜨리는 케이스
    for (int l = d_idx + 1; l <= d_idx + domino.range_l; l++)
        res = std::min(res, 1 + solve(l + 1));

    memo[d_idx] = res ? res : -1;
    return res;
}

int main()
{
    std::cin >> num_dominos;
    for (int i = 0; i < num_dominos; i++)
        std::cin >> dominos[i].pos >> dominos[i].height;
    
    std::sort(dominos, dominos + num_dominos, 
        [](const Domino& lhs, const Domino& rhs) { return lhs.pos < rhs.pos; });

    map_ranges();

    std::cout << solve();
}