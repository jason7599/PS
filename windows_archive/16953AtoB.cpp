#include <iostream>

using namespace std;

int main() {
    int start, end;
    cin>>start>>end;

    int count=1;
    while(start!=end) {
        if(end%10==1)
            end/=10;
        else if(!(end%2))
            end/=2;
        else break;

        if(end<start) break;
        count++;
    }

    if(start==end) cout<<count;
    else cout<<-1;
}