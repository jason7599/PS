#include <iostream>

using namespace std;

int main() {
    string myAH; cin>>myAH;
    string hisAH; cin>>hisAH;

    if(myAH.length() >= hisAH.length())
        cout<<"go";
    else cout<<"no";
}