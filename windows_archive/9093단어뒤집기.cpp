#include <iostream>
#include <string>

using namespace std;

string line;

void reverse(int start, int end) {

    if (start == end) return;

    int t = (end - start + 1) / 2;
    for (int i = 0; i < t; i++) {
        char temp = line[start + i];
        line[start + i] = line[end - i];
        line[end - i] = temp;
    }
}

int main() {

    int n; cin >> n;

    while (n--) {

        getline(cin, line);
        int len = line.length();

        for (int i = 0; i < len - 1; i++) {
            if (line[i] == ' ') continue;
            int j = i;
            cout << "Let's reverse " << line.substr(i, j) << '\n';
            while (line[++j] != ' ');
            // reverse(i, j - 1);
            i = j + 1;
            // cout << "j = " << j << '\n';
            // cout << "Skipping i to " << i << ", " << line[i] << '\n';
        }

        cout << line << '\n';

    }

}
