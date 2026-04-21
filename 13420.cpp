#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long lv, rv, v, exp;
        char op;
        scanf("%lld %c %lld = %lld", &lv, &op, &rv, &exp);

        switch (op)
        {
            case '+': v = lv + rv; break;
            case '-': v = lv - rv; break;
            case '*': v = lv * rv; break;
            case '/': v = lv / rv; break;
        }

        if (v == exp)
            printf("correct\n");
        else
            printf("wrong answer\n");
    }

    return 0;
}