#include <iostream>
#include <queue>

int main() {

    int N,L;
    std::cin>>N>>L;

    std::priority_queue<int> reachable;

    int temp;
    for(int i=0; i<N; i++) {
        std::cin>>temp;
        reachable.push(-temp);
    }

    while(-reachable.top()<L) {
        L++;
        reachable.pop();
    }

    std::cout<<L;

}