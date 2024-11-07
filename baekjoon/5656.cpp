#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    for (int i = 1;; i++)
    {
        int lv, rv;
        char op[2];

        scanf("%d %s %d", &lv, op, &rv);

        if (!strcmp(op, "E"))
            break;

        bool res = 0;
        if (!strcmp(op, ">"))
            res = lv > rv;
        else if (!strcmp(op, "<"))
            res = lv < rv;
        else if (!strcmp(op, ">="))
            res = lv >= rv;
        else if (!strcmp(op, "<="))
            res = lv <= rv;
        else if (!strcmp(op, "=="))
            res = lv == rv;
        else if (!strcmp(op, "!="))
            res = lv != rv;

        printf("Case %d: ", i);
        if (res)
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}