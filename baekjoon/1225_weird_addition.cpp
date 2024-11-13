#include <iostream>

using namespace std;

int main()
{
    int a_sum = 0, b_sum = 0;
    char c;
    while ((c = getchar()) != ' ')
        a_sum += c -'0';
    while ((c = getchar()) != '\n')
        b_sum += c - '0';
    cout << (long long)a_sum * b_sum;
    return 0;
}