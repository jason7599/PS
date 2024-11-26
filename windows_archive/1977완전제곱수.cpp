#include <iostream>
#include <math.h>

int main() {
    int start,end;
    std::cin>>start>>end;

    int sum=0,min;
    int i=0,temp=1;

    while(true) {
        temp=pow(++i,2);
        if(temp>end) break;
        if(temp>=start) {
            if(!sum) min=temp;
            sum+=temp;
        }
    }

    if(!sum) std::cout<<-1;
    else
        std::cout<<sum<<std::endl<<min;
}