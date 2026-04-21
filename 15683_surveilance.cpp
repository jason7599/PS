#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

// d, r, u, l
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

const int CAM_ROT_VAR[5] = {4, 2, 4, 4, 0};
const vector<int> CAM_DIRS[5] = {
    {0},
    {0, 2},
    {0, 1},
    {0, 1, 2},
    {0, 1, 2, 3}
};

struct Cam {
    pii pos;
    int type;
    int rot = 0;
};

int g_h, g_w;
bool walls[8][8];
int cam_cnt;
Cam cams[8];
int vis[8][8];
int vis_id = 1;

bool is_oob(int y, int x) {
    return y < 0 || y >= g_h || x < 0 || x >= g_w;
}

int cast_vis(int y, int x, int d) {
    int cnt = 0;
    for (; !is_oob(y, x) && !walls[y][x]; y += DIRS[d].first, x += DIRS[d].second) {
        if (vis[y][x] != vis_id) {
            vis[y][x] = vis_id;
            cnt++;
        }
    }
    return cnt;
}

int eval_coverage() {
    int coverage = 0;
    vis_id++;

    for (int c = 0; c < cam_cnt; c++) {
        const Cam& cam = cams[c];

        for (int cd : CAM_DIRS[cam.type]) {
            int d = (cam.rot + cd) % 4;
            coverage += cast_vis(cam.pos.first, cam.pos.second, d);
        }
    }
    
    return coverage;
}

int get_max_coverage(int cam_idx = 0) {
    if (cam_idx == cam_cnt) {
        return eval_coverage();
    }
    int max_coverage = 0;
    for (int rot = 0; rot <= CAM_ROT_VAR[cams[cam_idx].type]; rot++) {
        cams[cam_idx].rot = rot;
        max_coverage = max(max_coverage, get_max_coverage(cam_idx + 1));
    }
    return max_coverage;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> g_h >> g_w;

    int vac_cnt = g_h * g_w;
    for (int y = 0; y < g_h; y++) {
        for (int x = 0; x < g_w; x++) {
            int v;
            cin >> v;
            if (v == 6) {
                walls[y][x] = 1;
                vac_cnt--;
            } else if (v) {
                cams[cam_cnt++] = Cam{{y, x}, v - 1};
            }
        }
    }

    cout << vac_cnt - get_max_coverage() << '\n';
}
