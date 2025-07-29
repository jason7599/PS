#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0, __n = n; i < __n; i++)
#define RANGE(i, s, e) for(int i = s, __e = e; i <= __e; i++)
#define REP(n) FOR(__, n)
#define LF {cout << '\n';}
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF}
template<typename T> void upmax(T& v, const T& other) { v = max(v, other); }
template<typename T> void upmin(T& v, const T& other) { v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/**
ALG!
무조건 젤 큰 숫자들이 우선이야.

그럼 첫째... 같은 최댓값이 여러개 있으면?
ex)
1 2 9 3 5
9 9 2 3 1 5
아 이런경우엔 뭐 걍 젤 앞에 있는거 하면 되는거네 오케이.

그럼 이 상태에서 9로 맞추면,,
> 3 5
> 9 2 3 1 5
역시 이번엔 5가 최대니까 고고.

그럼 알고리즘은..
현 상태 (i, j) 에서, 이후 같이 등장하는 최대값을 찾아.
좀 더 수학적으로 쓰자면, arr[0][i'] == arr[1][j'] == x이라고 할때 x 최대를 찾는 거야.
그리고.. 반복.

수도코드:
f(i, j):
    * arr[0][i] ~ end 중, arr[1][j] ~ end에 존재하는 값 중 최댓값을 고르고, 각각의 idx 구하기
    f(i', j')

흠....
그니까 좀 단순하게 말해보자.
그냥 계속, 두 배열 중 공통되는 최댓값을 찾으면 되는거야.
맞지?

그럼 특정 idx이후로 어떤 값들이 남아있나 확인이 가능해야해...

최적화는 어떤게 가능할까?
가장 핵심 부분은, 최댓값 idx 찾기일듯.

pq를 쓰는거 어때?
pq<pii>.. // <val, idx>. val은 큰 순서대로, idx는 작은 순서대로.

아냐 별로야.........

*/

int n, m;
queue<int> idxs[2][101];

int ans[100];
int ans_len;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(i, 2) {
        FOR(j, input(i ? m : n)) {
            idxs[i][input()].push(j);
        }
    }

    for (int i = 0, j = 0; i < n && j < m;) {
        int ni = -1;
        for (int v = 100; v > 0; v--) {
            
        }
    }
}