#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;
    n=1000-n;

    int count = 0;
    int change[] = {500, 100, 50, 10, 5, 1};

    int index = 0;
    while(n) {
        while(n-change[index]>=0) {
            n-=change[index];
            count++;
        }
        index++;
    }

    cout<<count;
}