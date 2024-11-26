#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int potionCount, potionPrice[10], minPrice = 987654321;
vector<pair<int, int>> discount[10];
bool purchased[10];

void func(int purchasedCount = 0, int price = 0) {

    if (purchasedCount == potionCount) {
        minPrice = min(minPrice, price);
        return;
    }

    for (int potionIndex = 0; potionIndex < potionCount; potionIndex++) {
        if (purchased[potionIndex]) continue;

        purchased[potionIndex] = true; // buy this potion

        int potionPriceCopy[10];
        for (int i = 0; i < potionCount; i++)
            potionPriceCopy[i] = potionPrice[i];

        for (pair<int, int> discountInfo : discount[potionIndex]) {
            potionPrice[discountInfo.first] =
                max(1, potionPrice[discountInfo.first] - discountInfo.second);
        }

        func(purchasedCount + 1, price + potionPriceCopy[potionIndex]);

        for (int i = 0; i < potionCount; i++)
            potionPrice[i] = potionPriceCopy[i];

        purchased[potionIndex] = false;

    }

}

int main() {

    cin >> potionCount;

    for (int i = 0; i < potionCount; i++) {
        cin >> potionPrice[i];
    }
    for (int i = 0; i < potionCount; i++) {
        int discountCount;
        cin >> discountCount;
        while (discountCount--) {
            int itemIndex, discountRate;
            cin >> itemIndex >> discountRate;
            discount[i].push_back({ itemIndex - 1, discountRate });
        }
    }

    func();

    cout << minPrice;


}