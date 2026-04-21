#include <iostream>
#include <algorithm>

int calc(int a, char op, int b)
{
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return -1;
    }
}

int main()
{
    int a, b, c;
    char op0, op1;
    scanf("%d %c %d %c %d",
        &a, &op0, &b, &op1, &c);

    int res0 = calc(calc(a, op0, b), op1, c);
    int res1 = calc(a, op0, calc(b, op1, c));

    std::cout << std::min(res0, res1) << '\n';
    std::cout << std::max(res0, res1) << '\n';
}