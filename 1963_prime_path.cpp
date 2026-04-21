#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 9'999;

bool is_prime[MAX_VAL + 1];

void sieve() {
    fill(&is_prime[0], &is_prime[MAX_VAL + 1], 1);
    for (int i = 2; i * i <= MAX_VAL; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= MAX_VAL; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

int get_prime_dist(int src, int dst) {
    static int vis[MAX_VAL + 1];
    static int nx_vis_id = 1;

    if (src == dst) {
        return 0;
    }

    int vis_id = vis[src] = nx_vis_id++;
    queue<int> q({src});

    for (int q_size, dist = 0; (q_size = q.size()); dist++) {
        while (q_size--) {
            int cur = q.front();
            q.pop();
    
            for (int d = 1; d <= 1000; d *= 10) {
                int t = (cur / (d * 10)) * (d * 10) + (cur % d);
                for (int i = (d == 1000); i < 10; i++) {
                    int nx = t + i * d;
                    if (nx == dst) {
                        return dist + 1;
                    }
                    if (is_prime[nx] && vis[nx] != vis_id) {
                        vis[nx] = vis_id;
                        q.push(nx);
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    sieve();

    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        int src, dst;
        cin >> src >> dst;
        int dist = get_prime_dist(src, dst);
        if (dist == -1) {
            cout << "Impossible\n"; 
        } else {
            cout << dist << '\n';
        }
    }
}
