#include <iostream>
#include <queue>

using pii = std::pair<int, int>;

const int max_civs = 100'000;
const int max_map_size = 2000;

const int dys[] = {-1, 0, 1, 0};
const int dxs[] = {0, -1, 0, 1};

int num_civs;
int roots[max_civs + 1];

std::queue<pii> civs[max_civs + 1];

int map_size;
int map[max_map_size + 1][max_map_size + 1];
int visited_t[max_map_size + 1][max_map_size + 1];

bool is_oob(int y, int x)
{
    return y <= 0 || y > map_size || x <= 0 || x > map_size;
}

int get_root(int civ)
{
    if (roots[civ] == civ)
        return civ;
    return roots[civ] = get_root(roots[civ]);
}

int make_union(int civ0, int civ1)
{
    civ0 = get_root(civ0);
    civ1 = get_root(civ1);

    if (civ0 < civ1)
        return roots[civ1] = civ0;
    return roots[civ0] = civ1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> map_size >> num_civs;
    
    for (int civ = 1; civ <= num_civs; civ++)
    {
        int y, x;
        std::cin >> y >> x;
        
        map[y][x] = civ;
        civs[civ].push({y, x});

        roots[civ] = civ;
    }

    int num_merged = 0;

    for (int time = 1;; time++)
    {
        for (int civ = 1; civ <= num_civs; civ++)
        {
            auto& q = civs[civ];
            int q_size = q.size();
            
            while (q_size--)
            {
                const auto [y, x] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = y + dys[d];
                    int nx = x + dxs[d];

                    if (is_oob(ny, nx))
                        continue;
                    
                    if (!map[ny][nx])
                    {
                        map[ny][nx] = civ;
                        q.push({ny, nx});
                        visited_t[ny][nx] = time;

                        for (int dd = 0; dd < 4; dd++)
                        {
                            int nny = ny + dys[dd];
                            int nnx = nx + dxs[dd];

                            if (!is_oob(nny, nnx))
                            {
                                if (map[nny][nnx])
                                {
                                    if (get_root(map[nny][nnx]) != get_root(civ))
                                    {
                                        make_union(map[nny][nnx], civ);
                                        if (++num_merged == num_civs - 1)
                                        {
                                            std::cout << time;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (get_root(map[ny][nx]) != get_root(civ))
                    {
                        make_union(map[ny][nx], civ);

                        if (++num_merged == num_civs - 1)
                        {
                            std::cout << time - 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}