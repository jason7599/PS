#include <iostream>
#include <string>

using namespace std;

int main() {

    string input;
    getline(cin, input);

    char prev = input[0];
    int total = 0;
    int layer = prev == '(';
    int len = input.length();

    for (int i = 1; i < len; i++) {
        char cur = input[i];
        if (cur == '(') layer++;
        else {
            layer--;
            if (prev == '(') total += layer;
            else total++;
        }
        prev = cur;
    }

    cout << total;

}