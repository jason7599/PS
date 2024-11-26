#include <iostream>

using namespace std;

int cards[100];

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin >> cards[i];
    }

    int closest = 0;

    for(int a=0; a<n-2; a++) {
        int A = cards[a];
        if(A > m) continue;
        for(int b=a+1; b<n-1; b++) {
            int B = cards[b];
            if(A + B > m) continue;
            for(int c=b+1; c<n; c++) {
                int C = cards[c];
                if(A + B + C > m) continue;
                if(m - closest > m - A - B - C) {
                    closest = A + B + C;
                    if(closest == m) {
                        cout<<closest;
                        return 0;
                    }
                }
            }
        }
    }

    cout<< closest;
}