#include <iostream>
#include <map>
#include <string>
#include <cmath>

int main() {
    std::string roomNo;
    std::cin>>roomNo;

    std::map<char,int> numCount;
    for(char c : roomNo)
        numCount[c]++;

    int sixAndNines=std::round((numCount['6']+numCount['9'])/2.0);
    int max=0;
    for(auto it : numCount)
        if(max<it.second && (it.first!='6' && it.first!='9')) max=it.second;

    std::cout<<std::max(sixAndNines,max);
}