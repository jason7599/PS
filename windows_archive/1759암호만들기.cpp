#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int length, alphabetCount;
char alphabets[15];

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void func(int index, int vowelCount, string res) {

    if (res.length() == length) {
        if (vowelCount && length - vowelCount > 1)
            cout << res << '\n';
        return;
    }

    for (int i = index; i < alphabetCount; i++) {
        func(i + 1, vowelCount + isVowel(alphabets[i]), res + alphabets[i]);
    }

}

int main() {

    cin >> length >> alphabetCount;

    for (int i = 0; i < alphabetCount; i++) {
        cin >> alphabets[i];
    }

    sort(alphabets, alphabets + alphabetCount);

    func(0, 0, "");

}