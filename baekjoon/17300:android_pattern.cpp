#include <iostream>
#include <vector>

bool is_pattern_legal(const std::vector<int>& pattern)
{
    bool visited[3][3] = {0};

    for (int i = 0; i < pattern.size(); i++)
    {
        int row = (pattern[i] - 1) / 3;
        int col = (pattern[i] - 1) % 3;

        if (visited[row][col])
            return 0;
        
        visited[row][col] = 1;

        if (i)
        {
            int p_row = (pattern[i - 1] - 1) / 3;
            int p_col = (pattern[i - 1] - 1) % 3;

            int d_row = row - p_row;
            int d_col = col - p_col;

            if (!(d_row % 2) && !(d_col % 2))
            {
                if (!visited[p_row + d_row / 2][p_col + d_col / 2])
                    return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int pattern_len;
    std::vector<int> pattern;

    std::cin >> pattern_len;
    pattern.resize(pattern_len);

    for (int i = 0; i < pattern_len; i++)
        std::cin >> pattern[i];
    
    std::cout << (is_pattern_legal(pattern) ? "YES" : "NO");
}