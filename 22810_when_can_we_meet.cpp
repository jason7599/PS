#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    while (1)
    {
        int n_members, quorum;
        std::cin >> n_members >> quorum;

        if (!n_members && !quorum)
            break;

        std::unordered_map<int, int> cnt;

        int max_freq = 0;
        int max_freq_date = 100;

        while (n_members--)
        {
            int n_dates;
            std::cin >> n_dates;

            while (n_dates--)
            {
                int date;
                std::cin >> date;
                
                if (++cnt[date] > max_freq)
                {
                    max_freq = cnt[date];
                    max_freq_date = date;
                }
                else if (cnt[date] == max_freq && max_freq_date > date)
                    max_freq_date = date;
            }
        }

        if (max_freq >= quorum)
            std::cout << max_freq_date;
        else
            std::cout << 0;
        std::cout << '\n';
    }
}