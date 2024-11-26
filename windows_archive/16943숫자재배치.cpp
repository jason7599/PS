/**
 * Greedy로 안되는 경우가 있다.
 * 
 * 2412 -> 2411
 * 
 * 24로 시작하면 ㅈ망.
 * 정답은 2241.
 * 
 * f(i):
 * i 랑 j swap, 재귀
 * swap 없이 재귀
 */


#include <iostream>
#include <string>

using namespace std;

int c(string& a, const int b, int index = 0)
{
    if (index == a.length())
    {
        int ai = stoi(a);
        if (ai < b)
            return ai;
        return -1;
    }

    int ans = c(a, b, index + 1);

    char this_char = a[index];
    for (int swap = index + 1; swap < a.length(); swap++)
    {
        char swap_char = a[swap];
        if (index == 0 && swap_char == '0')
            continue;

        a[swap] = this_char;
        a[index] = swap_char;
        
        int temp = c(a, b, index + 1);
        if (temp > ans)
            ans = temp;

        a[swap] = swap_char;
    }
    a[index] = this_char;

    return ans;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;

    cout << c(a, b);

    return 0;
}