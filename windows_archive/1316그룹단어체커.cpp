#include <iostream>
#include <string>
#include <map>

bool isGroupWord(std::string word) {
    std::map<char, bool> history;
    char prev=NULL, curr;

    for(char c : word) {
        curr=c;
        if(history[curr]) return false;
        if(prev!=curr && prev)
            history[prev]=true;
        prev=c;
    }
    return true;
}

int main() {
    int n;
    std::cin>>n;

    std::string *words = new std::string[n];
    for(int i=0; i<n; i++)
        std::cin>>words[i];
    
    int count=0;
    for(int i=0; i<n; i++)
        if(isGroupWord(words[i])) count++;
    
    std::cout<<count;
    delete [] words;
}