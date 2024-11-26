#include <iostream>

using namespace std;

bool isPrime(int n) {
    if(n==1) return false;
    for(int i=2; i<n; i++)
        if(!(n%i)) return false;
    return true;
}

void goldBach(int n) {
    for(int x = 1; x<n; x++) {
        if(isPrime(x) && isPrime(n-x)) {
            cout<<n<<" = "<<x<<" + "<<n-x<<'\n';
            return;
        }
    }
    cout<<"Goldbach's conjecture is wrong.\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true) {
        int input; cin>>input;
        if(!input) return 0; 
        goldBach(input);
    }
}