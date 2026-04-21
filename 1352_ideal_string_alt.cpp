#include <iostream>
#include <vector>

void fuck(int idx, int len)
{
    static std::vector<int> vec;
    static int next = 1;

    if (!len)
    {
        for (int i : vec)
            std::cout << i << ' ';
        std::cout << '\n';
        return;
    }

    if (len - next < 0)
        return;
    
    
}

int main()
{

}