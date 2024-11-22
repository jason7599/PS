#include <stdio.h>
#include <algorithm>

int seq[(int)2e6];

int main()
{
    int seq_len;
    scanf("%d", &seq_len);
    for (int i = 0; i < seq_len; i++)
        scanf("%d", seq + i);

    std::sort(seq, seq + seq_len);

    
}