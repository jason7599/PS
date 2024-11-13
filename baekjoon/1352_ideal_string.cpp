#include <iostream>

char str[100];
int len;

void brute()
{
    static int req_sum;
    static int reqs[26]; // 0 if not used, -1 if done
    static int nx_unused;
    static int str_len;

    if (str_len == len)
    {
        if (!req_sum)
        {
            for (int i = 0; i < str_len; i++)
                std::cout << str[i];
            std::exit(0);
        }
    }
        // return !req_sum;

    // case 1: if exists, take care of req
    int sum = 0; // for early termination
    for (int i = 0; i < nx_unused; i++)
    {
        if (sum == req_sum)
            break;

        if (reqs[i] > 0)
        {
            int req = reqs[i];
            sum += req;
            
            if (!--reqs[i])
                reqs[i] = -1; // done

            req_sum--;
            str[str_len++] = i + 'A';

            brute();
            
            str_len--;
            req_sum++;

            reqs[i] = req;
        }
    }
    
    // case 2: start a new char
    int req = str_len; // no -1, accounting for this char being placed
    if (req_sum + req <= len - str_len - 1)
    {
        str[str_len++] = nx_unused + 'A';
        reqs[nx_unused] = nx_unused ? req : -1; // 'A' is finished immediately
        req_sum += req;
        nx_unused++;

        brute();

        str_len--;
        reqs[--nx_unused] = 0;
        req_sum -= req;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> len;
    brute();
    std::cout << -1;
}