#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

#define INF 987654321

using namespace std;

int targetChannel, leastPresses = INF;
bool broken[10];

int countPresses(int channel) {
    string channel_s = to_string(channel);
    for (char c : channel_s) {
        if (broken[c - '0'])
            return -1;
    }
    return channel_s.length();
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> targetChannel;

    int brokenCount; cin >> brokenCount;
    while (brokenCount--) {
        int temp; cin >> temp;
        broken[temp] = true;
    }

    int higher = INF, lower = INF;

    for (int channel = targetChannel; channel < targetChannel * 2; channel++) {
        int temp = countPresses(channel);
        if (temp != -1) {
            higher = temp + channel - targetChannel;
            break;
        }
    }
    for (int channel = targetChannel; ; channel--) {
        if (channel < 0) break;
        int temp = countPresses(channel);
        if (temp != -1) {
            lower = temp + targetChannel - channel;
            break;
        }
    }

    cout << min(abs(100 - targetChannel), min(higher, lower));


}