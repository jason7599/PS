#include <iostream>
#include <string>

struct Url
{
    std::string protocol;
    std::string host;
    std::string port;
    std::string path;
};

std::string get_token(
    const std::string& src,
    const std::string& pattern,
    size_t& pos)
{
    size_t f = src.find(pattern, pos);

    if (f == std::string::npos)
        return "";

    std::string res = src.substr(pos, f - pos);
    pos = f + pattern.length();
    return res;
}

Url parse_url(const std::string& line)
{
    Url url;
    size_t pos = 0;

    url.protocol = get_token(line, "://", pos);
    
    std::string t = get_token(line, ":", pos);
    if (t.empty())
    {
        url.port = "<default>";
        url.host = get_token(line, "/", pos);
        if (url.host.empty())
        {
            url.host = line.substr(pos);
            url.path = "<default>";
        }
        else
        {
            url.path = line.substr(pos);
        }
    }
    else
    {
        url.host = t;
        url.port = get_token(line, "/", pos);
        if (url.port.empty())
        {
            url.port = line.substr(pos);
            url.path = "<default>";
        }
        else
        {
            url.path = line.substr(pos);
        }
    }

    return url;
}

void print_url(const Url& url)
{
    std::cout << "Protocol = " << url.protocol << '\n';
    std::cout << "Host     = " << url.host << '\n';
    std::cout << "Port     = " << url.port << '\n';
    std::cout << "Path     = " << url.path << '\n';
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int num_urls;
    std::cin >> num_urls;
    std::cin.ignore();

    for (int i = 1; i <= num_urls; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        Url url = parse_url(line);

        std::cout << "URL #" << i << '\n';
        print_url(url);
        if (i != num_urls - 1)
            std::cout << '\n';
    }
}