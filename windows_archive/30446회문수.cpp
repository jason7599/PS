#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int num_palindromes_of_length(int length)
{
    return 9 * pow(10, (length + 1) / 2 - 1);
}

int num_palindromes_of_same_digit_but_lesser_than(const string& num)
{
    
}

int main()
{
    string n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i < n.length(); i++)
        ans += num_palindromes_of_length(i);
    


    cout << ans;
    return 0;
}