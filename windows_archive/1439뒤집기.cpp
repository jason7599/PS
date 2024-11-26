#include <iostream>
#include <string>

int flipTo(std::string str, char target) {
    int count=0;
    char prev=NULL,cur;
    for(char c : str) {
        cur=c;
        if(cur!=target && (prev==target || !prev))
            count++;
        prev=cur;
    }
    return count;
}

int main() {
    std::string input;
    std::cin>>input;
    
    int count = flipTo(input,'0')<flipTo(input,'1')
                ?flipTo(input,'0'):flipTo(input,'1');
    
    std::cout<<count;
}