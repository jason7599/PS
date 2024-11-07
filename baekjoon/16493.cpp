#include <iostream>
#include <algorithm>

struct Chapter
{
    int days_required;
    int num_pages;
};

int num_chapters;
Chapter chapters[20];

int solve(int chapter, int days_remaining)
{
    static int memo[20][201];

    if (chapter == num_chapters || !days_remaining)
        return 0;
    
    if (memo[chapter][days_remaining])
        return std::max(memo[chapter][days_remaining], 0);
    
    int res = solve(chapter + 1, days_remaining);

    if (days_remaining >= chapters[chapter].days_required)
        res = std::max(res, chapters[chapter].num_pages + solve(chapter + 1, days_remaining - chapters[chapter].days_required));
    
    memo[chapter][days_remaining] = res ? res : -1;
    return res;
}

int main()
{
    int days_remaining;
    std::cin >> days_remaining >> num_chapters;

    for (int i = 0; i < num_chapters; i++)
        std::cin >> chapters[i].days_required >> chapters[i].num_pages;

    std::cout << solve(0, days_remaining);
}