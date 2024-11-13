#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::vector<std::map<char, int>> words;

    while (1)
    {
        std::string str;
        std::cin >> str;

        if (str == "-")
            break;
        
        std::map<char, int> word;

        for (char c : str)
            word[c]++;
        
        words.push_back(word);
    }

    while (1)
    {
        std::string str;
        std::cin >> str;

        if (str == "#")
            break;

        std::map<char, int> board;
        std::map<char, int> scores;

        for (char c : str)
        {
            board[c]++;
            scores[c] = 0;
        }

        for (const auto& word : words)
        {
            std::map<char, int> add_score;
            bool bad = 0;

            for (const auto& [c, cnt] : word)
            {
                if (board.find(c) == board.end() || board[c] < cnt)
                {
                    bad = 1;
                    break;
                }

                add_score[c]++;
            }

            if (!bad)
            {
                for (const auto [c, cnt] : add_score)
                    scores[c] += cnt;
            }
        }

        std::string min_scorers;
        std::string max_scorers;

        int min_score = words.size();
        int max_score = 0;

        for (const auto& [c, score] : scores)
        {
            min_score = std::min(min_score, score);
            max_score = std::max(max_score, score);
        }

        for (const auto& [c, score] : scores)
        {
            if (score == min_score)
                min_scorers += c;
            if (score == max_score)
                max_scorers += c;
        }

        std::cout << min_scorers << ' ' << min_score
            << ' ' << max_scorers << ' ' << max_score << '\n';
    }
}