#include <iostream>
#include <string>

int d(int n) {
    int sum=n;
    std::string _n = std::to_string(n);
    for(char c : _n) sum+=c-'0';
    return sum;
}

bool oneToTenK[10001]; //true if selfNum

int main() {

    for(int i=1; i<10001; i++)
        oneToTenK[i]=true;

    for(int i=1; i<10001; i++) {
        int temp = d(i);
        if (temp<10001)
            oneToTenK[temp]=false;
    }

    for(int i=1; i<10001; i++) {
        if(oneToTenK[i])
            std::cout<<i<<std::endl;
    }

}