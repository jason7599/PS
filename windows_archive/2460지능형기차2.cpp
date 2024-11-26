#include <iostream>

int main() {

    int on,off;
    int sum=0,max=0;

    for(int i=0; i<10; i++) {
        std::cin>>off>>on;
        sum+=-off+on;
        if(sum>max) max=sum;
    }

    std::cout<<max;

}