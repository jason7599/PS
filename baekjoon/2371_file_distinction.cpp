#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_files;
    std::cin >> n_files;

    std::vector<std::vector<int>> files(n_files);
    size_t max_len = 0;

    for (auto& file : files)
    {
        int x;
        while (std::cin >> x && x != -1)
            file.push_back(x);
        
        max_len = std::max(max_len, file.size());
    }

    std::vector<std::unordered_set<int>> uniques(max_len);

    for (int i = 0; i < n_files; i++)
    {
        int j = 0;
        for (; j < files[i].size(); j++)
            uniques[j].insert(files[i][j]);
        
        for (; j < max_len; j++)
            uniques[j].insert(-i - 1);
    }

    int k = 0;
    for (; uniques[k].size() != n_files; k++);

    std::cout << k + 1;
}