#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int truckCount, bridgeLength, maxWeight;
    cin>> truckCount>> bridgeLength>> maxWeight;

    queue<int> truckQueue;

    for(int i=0; i<truckCount; i++) {
        int temp;
        cin>>temp;
        truckQueue.push(temp);
    }

    int time=0;
    int curWeight=0;
    while(!truckQueue.empty()) {
        if(curWeight+truckQueue.front() <= maxWeight) {
            curWeight+=truckQueue.front();
            truckQueue.pop();
            time+=bridgeLength;
        }
    }
    
    cout<<time;

}