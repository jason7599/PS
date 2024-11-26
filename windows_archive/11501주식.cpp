#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        int m; cin>>m;
        vector<int> stocks; stocks.clear();
        priority_queue<int> stockPrices;
        
        for(int j=0; j<m; j++) {
            int input; cin>>input;
            stocks.push_back(input);
            stockPrices.push(input);
        }

        long long net=0;
        int stockCount=0;
        for(int j=0; j<m; j++) {
            int targetPrice = stockPrices.top();
            if(stocks[j]==targetPrice) {  //time to sell
                stockPrices.pop();
                net+=stockCount*targetPrice;
                stockCount=0;
            }
            else {  //fuck
                if(j!=m-1) {
                    net-=stocks[j];
                    stockCount++;
                }
            }
        }
        cout<<net<<'\n';
    }

}