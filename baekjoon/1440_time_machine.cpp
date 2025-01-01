#include <stdio.h>

int main()
{
    int t[3];
    scanf("%d:%d:%d", &t[0], &t[1], &t[2]);

    if ((t[0] > 59 || t[1] > 59 || t[2] > 59)
    || (!t[0] && !t[1] && !t[2])
    || (t[0] > 12 && t[1] > 12 && t[2] > 12))
    {
        printf("0");
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (1 <= t[i] && t[i] <= 12)
            ans += 2;
    }

    printf("%d", ans);
}