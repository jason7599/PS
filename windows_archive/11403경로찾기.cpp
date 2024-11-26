#include <iostream>

using namespace std;

int nodeCount;
bool adjacent[100][100];

int main() {

    cin >> nodeCount;

    for (int i = 0; i < nodeCount; i++)
        for (int j = 0; j < nodeCount; j++)
            cin >> adjacent[i][j];

    for (int k = 0; k < nodeCount; k++)
        for (int i = 0; i < nodeCount; i++)
            for (int j = 0; j < nodeCount; j++)
                if (adjacent[i][k] && adjacent[k][j])
                    adjacent[i][j] = true;

    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++)
            cout << adjacent[i][j] << ' ';
        cout << '\n';
    }
}