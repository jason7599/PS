#include <iostream>
#include <string>

using namespace std;

int Rev(int x) {
    string temp = to_string(x);
    string out = temp;
    for(int i=0; i<temp.length(); i++)
        out[temp.length()-i-1]=temp[i];
    return stoi(out);
}

int main() {
    int x,y;
    cin>>x>>y;
    cout<<Rev(Rev(x)+Rev(y));
}