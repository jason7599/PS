#include <iostream>
#include <queue>

int fuck(int state, int y, int x, int dy, int dx)
{
    for (int i = 0; i < 3; i++)
    {
        state ^= (1 << (y * 3 + x));
        y += dy;
        x += dx;
    }
    return state;
}

// maximum of 2^9 states
int solve(int init_state)
{
    bool visited[1 << 9] = {0};
    std::queue<int> q;

    visited[init_state] = 1;
    q.push(init_state);

    int flips = 0;
    size_t q_size;
    while ((q_size = q.size()))
    {
        while (q_size--)
        {
            int state = q.front();
            q.pop();

            if (!state || state == (1 << 9) - 1)
                return flips;
            
            int nstates[8];

            for (int i = 0; i < 3; i++)
            {
                nstates[i * 2] = fuck(state, i, 0, 0, 1);
                nstates[i * 2 + 1] = fuck(state, 0, i, 1, 0); 
            }

            nstates[6] = fuck(state, 0, 0, 1, 1);
            nstates[7] = fuck(state, 2, 0, -1, 1);

            for (int nstate : nstates)
            {
                if (!visited[nstate])
                {
                    visited[nstate] = 1;
                    q.push(nstate);
                }
            }
        }
        flips++;
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;
    while (n_tc--)
    {
        // 1 for heads
        int state = 0;
        for (int i = 0; i < 9; i++)
        {
            char c;
            std::cin >> c;
            if (c == 'H')
                state |= (1 << i);
        }

        std::cout << solve(state) << '\n';
    }
}