#include <iostream>
#include <string>
#include <algorithm>

char cache[100][100]; // pi, fi

bool matches(const std::string& filename, 
             const std::string& pattern,
             size_t fi = 0, size_t pi = 0)
{
    if (pi == pattern.length())
        return pattern.back() == '*' || fi == filename.length();

    if (fi == filename.length())
        return pi == pattern.length() - 1 && pattern.back() == '*'; 

    if (cache[pi][fi] != -1)
        return cache[pi][fi];

    if (pattern.at(pi) == '*')
        return cache[pi][fi] = matches(filename, pattern, fi + 1, pi)
            || matches(filename, pattern, fi + 1, pi + 1)
            || matches(filename, pattern, fi, pi + 1);
    
    return cache[pi][fi] = 
            filename.at(fi) == pattern.at(pi)
            && matches(filename, pattern, fi + 1, pi + 1);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::string pattern;
    std::cin >> pattern;

    int n_files;
    std::cin >> n_files;

    while (n_files--)
    {
        std::string filename;
        std::cin >> filename;

        for (size_t i = 0; i < pattern.length(); i++)
            std::fill(&cache[i][0], &cache[i][filename.length()], -1);

        if (matches(filename, pattern))
            std::cout << filename << '\n';
    }
}