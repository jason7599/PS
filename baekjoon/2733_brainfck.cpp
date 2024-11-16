#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

const int mem_size = 32768;
const int max_instrs = 128'000;

struct instr
{
    char type;
    int val; // only used for jumps
};

const char i_inc_ptr = '>';
const char i_dec_ptr = '<';
const char i_inc_val = '+';
const char i_dec_val = '-';
const char i_out = '.';
const char i_loop_s = '[';
const char i_loop_e = ']';

int num_instrs;
instr instrs[max_instrs];
unsigned char mem[mem_size];

bool compile(const std::vector<std::string>& lines)
{
    std::stack<int> loop_stk;
    num_instrs = 0;

    for (const auto& line : lines)
    {
        for (char c : line)
        {
            if (c == '%')
                break;

            switch (c)
            {
            case i_inc_ptr:
            case i_dec_ptr:
            case i_inc_val:
            case i_dec_val:
            case i_out:
                instrs[num_instrs++].type = c;
                break;
            case i_loop_s:
                loop_stk.push(num_instrs);
                instrs[num_instrs++].type = c;
                break;
            case i_loop_e:
                if (loop_stk.empty())
                    return 0;
                instrs[loop_stk.top()].val = num_instrs;
                instrs[num_instrs].val = loop_stk.top();
                loop_stk.pop();
                instrs[num_instrs++].type = c;
                break;
            }
        }
    }

    return loop_stk.empty();
}

void run()
{
    int iptr = 0;
    int mptr = 0;

    while (iptr < num_instrs)
    {
        switch (instrs[iptr].type)
        {
        case i_inc_ptr:
            mptr = (mptr + 1) % mem_size;
            break;
        case i_dec_ptr:
            if (!mptr--)
                mptr = mem_size - 1;
            break;
        case i_inc_val:
            mem[mptr]++;
            break;
        case i_dec_val:
            mem[mptr]--;
            break;
        case i_out:
            std::cout << mem[mptr];
            break;
        case i_loop_s:
            if (!mem[mptr])
                iptr = instrs[iptr].val;
            break;
        case i_loop_e:
            if (mem[mptr])
                iptr = instrs[iptr].val;
            break;
        }

        iptr++;
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int num_progs;
    std::cin >> num_progs;
    std::cin.ignore();

    for (int pn = 1; pn <= num_progs; pn++)
    {
        std::vector<std::string> lines;
        while (1)
        {
            std::string line;
            std::getline(std::cin, line);
            if (line == "end")
                break;
            lines.push_back(line);
        }

        std::cout << "PROGRAM #" << pn << ":\n";
        if (compile(lines))
        {
            run();
            std::cout << '\n';
            if (pn != num_progs)
                std::fill(mem, mem + mem_size, 0);
        }
        else
            std::cout << "COMPILE ERROR\n";
    }
}