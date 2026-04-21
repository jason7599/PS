#include <iostream>
#include <string>
#include <algorithm>

int main()
{
int n;
std::cin >> n;
for (int i = 1;
i <= n;
i++)
{
std::string s;
std::cin >> s;
if (!std::next_permutation(s.begin(), s.end()))
std::cout << "USELESS";
else std::cout << s;
std::cout << '\n';
}
}