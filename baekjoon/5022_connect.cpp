#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int g_h, g_w;
int vis[102][102];
int vid = 1;

void input_pii(pii& p) {
    cin >> p.first >> p.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_h >> g_w;

    pii src_a, dst_a;
    input_pii(src_a);
    input_pii(dst_a);

    pii src_b, dst_b;
    input_pii(src_b);
    input_pii(dst_b);


}
