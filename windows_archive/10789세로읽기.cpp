#include <iostream>
#include <string>

using namespace std;

int main()
{
    string lines[5];
    for (int i = 0; i < 5; i++)
        cin >> lines[i];

    for(int i = 0; i < 15; i++)
    {
        bool done = true;
        for (string line : lines)
        {
            if (i < line.length())
            {
                done = false;
                cout << line[i];
            }
        }

        if (done) break;
    }
}