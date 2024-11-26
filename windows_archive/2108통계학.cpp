#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

bool cmp(std::pair<int,int>a,std::pair<int,int>b) {
    return a.second>b.second;
}

int main() {
    int n;
    std::cin>>n;
    std::vector<int> numList;
    std::map<int,int> numCount;

    int input,sum=0;
    for(int i=0; i<n; i++) {
        std::cin>>input;
        sum+=input;
        numList.push_back(input);
        numCount[input]++;
    }
    std::cout<<std::round(sum/n)<<std::endl; //1.산술평균
    std::sort(numList.begin(),numList.end());
    std::cout<<numList[n/2]<<std::endl;//2.중앙값

    std::vector<std::pair<int,int>> numCountV(numCount.begin(),numCount.end());
    std::sort(numCountV.begin(),numCount.end(),cmp);
}