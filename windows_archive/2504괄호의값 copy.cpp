#include <iostream>
#include <string>

using namespace std;

string input;
int input_len;

int eval()
{
    static int index = 0;

    int val = 0;
    char c, t;

    while (index < input_len)
    {
        c = input[index++];
        
        if (c == '(')
            t = ')';
        else if (c == '[')
            t = ']';
        else
        {
            cout << "WTHAJDHAJKL";
            return 0;
        }

        
    }
}

int main()
{
    cin >> input;
    input_len = input.length();


}