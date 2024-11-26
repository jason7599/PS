#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string raw_input;
    cin>>raw_input;

    vector<int> delimiterIndices;
    delimiterIndices.push_back(0);
    for(int i=0; i<raw_input.length(); i++)
        if(raw_input[i]=='+' || raw_input[i]=='-') 
            delimiterIndices.push_back(i);
    delimiterIndices.push_back(raw_input.length());

    vector<int> numbers;
    int minusIndex=NULL;
    string temp;
    for(int i=0; i<delimiterIndices.size()-1; i++) {
        temp=raw_input.substr(delimiterIndices[i],delimiterIndices[i+1]);
        if((stoi(temp)<0 || temp[0]=='-') && !minusIndex) minusIndex=i;
        numbers.push_back(abs(stoi(temp)));
    }

    // for(int i : numbers) cout<<i<<endl;
    
    int result=0;
    if(!minusIndex)
        for(int i : numbers) result+=i;
    else
        for(int i=0; i<numbers.size(); i++) {
            if(i<minusIndex) result+=numbers[i];
            else result-=numbers[i];
        }

    cout<<result;

}