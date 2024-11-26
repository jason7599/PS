#include <iostream>

int fuck(int n) {
    int ten=n/10;
    int one=n-ten*10;
    return 10*one+(ten+one)%10;
}

int main() {
    int start;
    std::cin>>start;

    int count=1;
    for(int cur=fuck(start);cur!=start;cur=fuck(cur),count++);

    std::cout<<count;
}