#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, arr[8];

void func(int count, int prev, string res) {
    
    if(count == m) {
        cout << res << '\n';
        return;
    }

    int lastVisited = -1;
    for(int i = prev + 1; i < n; i++) {
        if(arr[i] != lastVisited) {
            lastVisited = arr[i];
            func(count + 1, i, res + to_string(arr[i]) + ' ');
        }
    }
}

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++) 
        cin >> arr[i];

    sort(arr, arr+n);

    func(0, -1, "");

}