#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse_path(const std::string& url)
{
    std::vector<std::string> path;

    size_t base = 0;
    size_t t;
    while ((t = url.find('/', base)) != std::string::npos)
    {
        path.push_back(url.substr(base, t - base));
        base = t + 1;
    }
    path.push_back(url.substr(base));

    return path;
}

int main()
{
    std::string src_url, dst_url;
    std::cin >> src_url >> dst_url;

    auto src = parse_path(src_url);
    auto dst = parse_path(dst_url);

    size_t l_match = 0;
    while (l_match < src.size() && l_match < dst.size()
    && src[l_match] == dst[l_match])
        l_match++;

    size_t r_match = 0;
    while (r_match < src.size() && r_match < dst.size()
    && src[src.size() - 1 - r_match] == dst[dst.size() - 1 - r_match])
        r_match++;
    
    for (size_t i = 0; i < l_match; i++)
        std::cout << src[i] << '/';
    
    std::cout << '{';

    for (size_t i = l_match; i < src.size() - r_match; i++)
    {
        std::cout << src[i];
        if (i + 1 != src.size() - r_match)
            std::cout << '/';
    }

    std::cout << " => ";

    for (size_t i = l_match; i < dst.size() - r_match; i++)
    {
        std::cout << dst[i];
        if (i + 1 != dst.size() - r_match)
            std::cout << '/';
    }

    std::cout << '}';

    for (size_t i = 0; i < r_match; i++)
        std::cout << '/' << src[src.size() - r_match + i];

    std::cout << '\n';
}
