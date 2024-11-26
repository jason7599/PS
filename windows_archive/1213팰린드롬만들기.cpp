#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string input;
    cin>>input;

    vector<char> charList;
    for(char c : input)
        charList.push_back(c);
    sort(charList.begin(),charList.end());

    map<char,int> charCount;
    for(char c : charList)
        charCount[c]++;

    int length=input.length();
    int temp=0;
    char middle;
    if(!length%2){ //even length {
        for(auto i : charCount)
            if(i.second%2) { //odd count
                cout<<"I'm Sorry Hansoo";
                return 0;
            }
    }
    else { //odd length;
        for(auto i : charCount) {
            if(i.second%2) {
                temp++;
                middle=i.first;
                if(temp==2) {
                    cout<<"I'm Sorry Hansoo";
                    return 0;
                }
            }
        // charCount[middle]--;
        }
    }

    string palindrome=input;
    temp=0;
    for(auto i : charCount) {
        i.second/=2;
        while(i.second) {
            palindrome[temp++]=i.first;
            i.second--;
            if(temp>length/2) break;
        }
    }
    if(length%2) palindrome[length/2]=middle;
    for(int i=0; i<length/2; i++)
        palindrome[length-1-i]=palindrome[i];
    
    cout<<palindrome;

}