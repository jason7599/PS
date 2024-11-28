#include <iostream>
#include <string>
#include <queue>

char board[4][4];
bool used[4][4];


int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_words; // max 299'999!!
    std::cin >> n_words;

    std::vector<std::string> words(n_words);
    for (auto& word : words)
        std::cin >> word;

    int n_boards; // max 29
    std::cin >> n_boards;

    while (n_boards--)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
                std::cin >> board[y][x];
        }

        // max score, longest word, # words
    }
}