#include <iostream>

int beauty(int n)
{
    int beauty = 0;
    bool visited[10] = {0};

    while (n)
    {
        if (!visited[n % 10])
        {
            visited[n % 10] = 1;
            if (++beauty == 10)
                break;
        }
        n /= 10;
    }

    return beauty;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int x;
        std::cin >> x;
        std::cout << beauty(x) << '\n';
    }
}