#include <iostream>
#include <string>
#include <set>

using namespace std;

class Cave {

    string name;
    set<Cave> children;

    Cave(string name) {
        this->name = name;
    }

};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);



}