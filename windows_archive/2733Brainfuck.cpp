#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Program
{
public:
    bool Compile(const vector<string>& lines);
    void Execute();
private:
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_progs; cin >> num_progs;
    for (int prog_no = 1; prog_no <= num_progs; prog_no++)
    {
        vector<string> lines;
        while (true)
        {
            string line; cin >> line;
            if (line == "end")
                break;
            lines.push_back(line);
        }
    }

    return 0;
}