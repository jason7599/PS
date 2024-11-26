#include <iostream>
#include <string>

int main() {

    std::string s1,s2;
    std::cin>>s1>>s2;

    char temp =s1[0];
    s1[0]=s1[2];
    s1[2]=temp;

    temp=s2[0];
    s2[0]=s2[2];
    s2[2]=temp;

    int n1,n2;
    n1=std::stoi(s1);
    n2=std::stoi(s2);

    int res = n1<n2? n2 : n1;
    std::cout<<res;

}