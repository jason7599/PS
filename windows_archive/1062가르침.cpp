#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int wordCount, letterCount, ans;
bitset<26> taught, words[50];

void func(int prevIndex, int lettersTaught) {

    // 글자를 다 정한 다음에 계산
    if (lettersTaught == letterCount) {
        int wordsTaught = 0;
        for (int w = 0; w < wordCount; w++)
            if ((words[w] & taught) == words[w])
                wordsTaught++;
        if (ans < wordsTaught) ans = wordsTaught;
        return;
    }

    for (int l = prevIndex + 1; l < 26; l++) {
        taught.set(l);
        func(l, lettersTaught + 1);
        taught.reset(l);
    }

}

int main() {

    cin >> wordCount >> letterCount;

    for (int i = 0; i < wordCount; i++) {
        string word; cin >> word;
        for (char c : word)
            words[i].set(c - 'a');

    }

    func(-1, 0);
    cout << ans;

}