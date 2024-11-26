#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int ARR_LEN = 32768;
const int MAX_INSTRS = 128'000;

enum instr_type
{
    PTR, BYTE, OUT, DO, WHILE, END
};

struct instr
{
    instr_type type;
    int val;
};

class Program
{
public:
    bool Compile(const vector<string>& lines);
    void Execute();
private:
    char arr[ARR_LEN];
    instr instrs[MAX_INSTRS + 1];
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

        Program prog;
        cout << "PROGRAM #" << prog_no << ":\n";
        if (prog.Compile(lines))
            prog.Execute();
        else
            cout << "COMPILE ERROR";
        cout << '\n';
    }

    return 0;
}

bool Program::Compile(const vector<string>& lines)
{
    int i = -1;
    stack<int> s;

    for (string line : lines)
    {
        for (char c : line)
        {
            if (c == '%')
                break;

            switch (c)
            {
            default:
                break;
            i++;
            case '>':
                instrs[i] = {PTR, 1};
                break;
            case '<':
                instrs[i] = {PTR, -1};
                break;
            case '+':
                instrs[i] = {BYTE, 1};
                break;
            case '-':
                instrs[i] = {BYTE, -1};
                break;
            case '.':
                instrs[i] = {OUT};
                break;
            case '[':
                instrs[i] = {DO};
                s.push(i);
                break;
            case ']':
                if (s.empty())
                    return false;
                instrs[i] = {WHILE, s.top()};
                instrs[s.top()].val = i;
                s.pop();
                break;
            }
        }
    }

    return true;
}