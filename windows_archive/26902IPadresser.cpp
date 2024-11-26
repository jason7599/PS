#include <iostream>
#include <string>

using namespace std;

// void print(const string& str, const int dot_idxs[3])
// {
//     int dot_idx = 0;

//     for (int i = 0; i < str.length(); i++)
//     {
//         cout << str[i];
//         if (dot_idx < 3 && i == dot_idxs[dot_idx])   
//         {
//             cout << '.';
//             dot_idx++;
//         }
//     }
//     cout << '\n';
// }

void func(const string& str, int idx = 0)
{
    static int dot_idxs[3];
    static int num_dots;

    
}

int main()
{
    string str;
    cin >> str;

    func(str);

    cout << ans;

    return 0;
}