#include <bits/stdc++.h>
using namespace std;

struct Op {
    char c;
    int v;
};

int mem_size, prog_len, input_len;
uint8_t mem[100'000];
Op prog[4096];
char input[4096];

pair<int, int> check_loop() {
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_tc;
    cin >> n_tc;
    while (n_tc--) {
        cin >> mem_size >> prog_len >> input_len;

        stack<int> loop_stk;
        for (int i = 0; i < prog_len; i++) {
            cin >> prog[i].c;
            if (prog[i].c == '[') {
                loop_stk.push(i);
            } else if (prog[i].c == ']') {
                int t = loop_stk.top();
                loop_stk.pop();
                prog[t].v = i;
                prog[i].v = t;
            }
        }

        for (int i = 0; i < input_len; i++) {
            cin >> input[i];
        }

        if (n_tc) {
            fill(&mem[0], &mem[mem_size], 0);
        }
    }    
}
