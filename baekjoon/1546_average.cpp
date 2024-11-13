#include <iostream>
#include <algorithm>

int main()
{
    int scores[1000], num_tests;
    std::cin >> num_tests;

    int best_score = 0;
    for (int i = 0; i < num_tests; i++)
    {
        std::cin >> scores[i];
        best_score = std::max(best_score, scores[i]);
    }

    double new_score_sum = 0;

    for (int i = 0; i < num_tests; i++)
    {
        double new_score = (double)scores[i] / best_score * 100;
        new_score_sum += new_score; 
    }

    std::cout << new_score_sum / num_tests;
}