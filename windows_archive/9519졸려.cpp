#include <iostream>
#include <string>

using namespace std;

string restore(string str) {
    string res = str;
    for(int i = 0, r = 0; i < str.length(); i += 2, r++) res[r] = str[i];
    for(int i = 1, r = 1; i < str.length(); i += 2, r++) res[str.length() - r] = str[i];
    return res;
}

int main() {

    int n;
    string str;
    cin >> n >> str;

    string arr[1000];
    arr[0] = str;

    for (int i = 1; i <= n; i++) {
        arr[i] = restore(arr[i - 1]);
        if (arr[i] == arr[0]) {
            cout << arr[n % i];
            return 0;
        }
    }
    cout << arr[n];

}