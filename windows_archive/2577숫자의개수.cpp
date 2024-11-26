#include <iostream>
#include <string>

int main() {
    int a,b,c;
    std::cin>>a>>b>>c;
    std::string res = std::to_string(a*b*c);

    int count[10]={0};

    for(int i=0; i<res.length(); i++)
        count[res[i]-'0']++;

    for(int i=0; i<10; i++)
        std::cout<<count[i]<<std::endl;
}