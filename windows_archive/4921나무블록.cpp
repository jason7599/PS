#include <iostream>
#include <string>

using namespace std;

// type: shape
// 0: flat, -1: rect_in, 1: rect_out, -2: round_in, 2: round_out

int r_shape[9] = {0, -1, 0, -1, 1, -2, 1, -2, 2};
int l_shape[9] = {0, 5, -1, -1, 1, 1, -2, -2, 2};

int main()
{
    for (int i = 1;; i++)
    {
        string line;
        cin >> line;
        if (line == "0")
            break;
        
        bool valid = true;
        if (line[0] != '1' || line[line.length() - 1] != '2')
            valid = false;
        else
        {
            for (int j = 1; j < line.length(); j++)
            {
                if (l_shape[line[j] - '0'] + r_shape[line[j - 1] - '0'] != 0)
                {
                    valid = false;
                    break;
                }
            }
        }
        cout << i << ". ";
        if (valid)
            cout << "VALID";
        else
            cout << "NOT";
        cout << '\n';
    }

    return 0;
}