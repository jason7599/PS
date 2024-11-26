#include <iostream>
#include <string>

using namespace std;

string file, key;

int find(int index = 0) {
    if (index == file.length()) return 0;
    if (file.substr(index, key.length()) == key)
        return 1 + find(index + key.length());
    return find(index + 1);
}

int main() {

    getline(cin, file);
    getline(cin, key);

    cout << find();

}