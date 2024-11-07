#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1;; i++)
    {
        string line;
        getline(cin, line);

        if (line == "Was it a cat I saw?")
            break;
        
        for (int j = 0; j < line.length(); j += i + 1)
            cout << line[j];
            
        cout << '\n';
    }

    return 0;
}