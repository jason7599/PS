#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m, arr[8];
bool visited[8];

void func(int count, string res) {
    
    if(count == m) {
        cout << res << '\n';
        return;
    }

    int lastVisited = -1;

    for(int i=0; i<n; i++) {
        if(visited[i] || arr[i] == lastVisited) continue;
        lastVisited = arr[i];
        visited[i] = true;
        func(count + 1, res + to_string(arr[i]) + ' ');
        visited[i] = false;
    }
}

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    func(0, "");

}