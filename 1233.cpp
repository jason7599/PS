#include <iostream>
#include <unordered_map>

int main()
{
    int s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    std::unordered_map<int, int> freq;
    int max_freq = 0;
    int max_freq_val;

    for (int i1 = 1; i1 <= s1; i1++)
    {
        for (int i2 = 1; i2 <= s2; i2++)
        {
            for (int i3 = 1; i3 <= s3; i3++)
            {
                int val = i1 + i2 + i3;
                if (++freq[val] > max_freq)
                {
                    max_freq = freq[val];
                    max_freq_val = val;
                }
            }
        }
    }

    std::cout << max_freq_val;
}