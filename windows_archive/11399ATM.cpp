#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n,input;
    std::cin>>n;
    std::vector<int> myVec;
    for(int i=0; i<n; i++) {
        std::cin>>input;
        myVec.push_back(input);
    }
    std::sort(myVec.begin(),myVec.end());
    int sum=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            sum+=myVec[j];
    std::cout<<sum;
}