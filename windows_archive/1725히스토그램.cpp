#include <iostream>
#include <algorithm>

using namespace std;

int width, histogram[100'000];

int func(int left, int right) {

    if (left == right) return histogram[left];

    int mid = (left + right) / 2;
    int res = max(func(left, mid), func(mid + 1, right));

    int l = mid, r = mid + 1;
    int h = min(histogram[l], histogram[r]);
    res = max(res, h * 2);

    while (left < l || r < right) {
        if (r < right && (l == left || histogram[l - 1] < histogram[r + 1]))
            h = min(h, histogram[++r]);
        else h = min(h, histogram[--l]);
        res = max(res, h * (r - l + 1)); // *******
    }

    return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> width;

    for (int i = 0; i < width; i++) cin >> histogram[i];

    cout << func(0, width - 1);

}