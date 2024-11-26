#include <iostream>

using namespace std;

int min_ = 1000000000;
int max_ = -100000000;

int n;
int operands[11];
int operators[4];

void brute(int index, int current) {
    if(index == n) {
        if(min_ > current) min_ = current;
        if(max_ < current) max_ = current;
        return;
    }
    for(int i=0; i<4; i++) {
        if(!operators[i]) continue;
        operators[i]--;

        if(i==0)      brute(index+1, current + operands[index]);
        else if(i==1) brute(index+1, current - operands[index]);
        else if(i==2) brute(index+1, current * operands[index]);
        else if(i==3) brute(index+1, current / operands[index]);

        operators[i]++;
    }
    return;
}

int main() {

    cin>>n;

    for(int i=0; i<n; i++)
        cin>>operands[i];

    for(int i=0; i<4; i++)
        cin>>operators[i];

    brute(1,operands[0]);

    cout<<max_<<'\n'<<min_;

}
