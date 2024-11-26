#include <iostream>
#include <algorithm>

using namespace std;

int leak_pos[1'001];

/**
 * 새는 각 지점 순회.
 * 각 지점에서 방금 전 지점과 거리를 따져
 * 그 거리가 테이프 거리보다 크면 방금 전 지점에 테이프를 붙여
 * 거리가 딱 맞아도 붙여
 * 
 * prev_pos = 테이프가 안 붙여진 방금 지점. 
 * 더 자세히 말하자면, 하나의 테이프가 붙여져야할 첫번째 지점이랄까
 * 즉 tape_len = 5라고 해보자. 1 2 3 4 5 라면 prev_pos = 1이야.
 * 1 ~ 5까지 딱 붙이면 되니까 
 * 테이프를 붙였다면 -1로 초기화.
 * 
 * 따라서 지금 지점(this_pos)과 prev_pos를 따져보는데
 * 
 * 1. prev_pos == -1인 경우 앞에껀 다 붙였다는 거니까 
 * prev_pos = this_pos 하고 넘어가. 당장 테이프 안 붙였으니까
 * 
 * len = this_pos - prev_pos + 1
 * 
 * 2. len < tape_len인 경우 당장 안 붙여도 되잖아?
 * 그리고 이런 경우 prev_pos를 건드리지 마.
 * 
 */

int main()
{
    int leak_count, tape_len;
    cin >> leak_count >> tape_len;

    for (int i = 0; i < leak_count; i++)
        cin >> leak_pos[i];

    sort(leak_pos, leak_pos + leak_count);

    int tape_count = 0;
    int prev_pos = -1;

    for (int i = 0; i < leak_count; i++)
    {
        int this_pos = leak_pos[i];

        if (prev_pos == -1)
        {
            prev_pos = this_pos;
            continue;
        }

        int len = this_pos - prev_pos + 1;

        if (len == tape_len)
        {
            tape_count++;
            prev_pos = -1;
        }
        else if (len > tape_len)
        {
            tape_count++;
            prev_pos = this_pos;
        }
    }

    if (prev_pos != -1)
        tape_count++;
    
    cout << tape_count;
    
    return 0;
}