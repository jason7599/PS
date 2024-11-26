#include <iostream>

bool isPrime(int n) {
    int count=0;
    for(int i=1; i<=n; i++)
        if(!(n%i)) count++;
    return count==2;
}

int main() {

    int n;
    std::cin>>n;
    int temp,count=0;
    for(int i=0; i<n; i++) {
        std::cin>>temp;
        if(isPrime(temp)) count++;
    }

    std::cout<<count;
}