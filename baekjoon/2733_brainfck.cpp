#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

const int ptr_max_addr = 32767;
const int max_instrs = 128000;
const int mem_size = 32768;

struct instr
{
    char type;
    int val;
};

const char instr_inc_ptr = '>';
const char instr_dec_ptr = '<';
const char instr_inc_val = '+';
const char instr_dec_val = '-';
const char instr_print = '.';
const char instr_jmp_l = '[';
const char instr_jmp_r = ']';

int num_instrs;
instr instrs[max_instrs];

unsigned char mem[mem_size];

// returns 0 on failed
bool compile(const std::vector<std::string> lines)
{
    num_instrs = 0;

    std::stack<int> jmp_ls;

    for (const auto& line : lines)
    {
        for (char c : line)
        {
            if (c == '%')
                break;

            switch (c)
            {
            case instr_inc_ptr:
            case instr_dec_ptr:
            case instr_inc_val:
            case instr_dec_val:
            case instr_print:
                instrs[num_instrs++].type = c;
                break;

            case instr_jmp_l:
                jmp_ls.push(num_instrs);
                instrs[num_instrs++].type = c;
                break;

            case instr_jmp_r:
                if (jmp_ls.empty())
                    return 0;
                int l = jmp_ls.top();
                jmp_ls.pop();

                instrs[l].val = num_instrs;
                instrs[num_instrs].type = c;
                instrs[num_instrs++].val = l;
                break;
            }
        }
    }

    return jmp_ls.empty();
}

void debug_print()
{
    for (int i = 0; i < num_instrs; i++)
    {
        char c = instrs[i].type;
        if (c == instr_jmp_l)
            std::cout << "(+" << instrs[i].val << ')';
        else if (c == instr_jmp_r)
            std::cout << "(-" << instrs[i].val << ')';
        else
            std::cout << c;
    }
    std::cout << '\n';
}

void run()
{
    int ptr = 0;
    bool brk = 0;
    while (!brk)
    {
        instr instr = instrs[ptr];
        switch (instr.type)
        {
        case instr_jmp_l:
            if (mem[ptr])
            {
                brk = 1;
                break;
            }
            ptr = instr.val;
            // fall thru
        case instr_inc_ptr:
            if (ptr++ == ptr_max_addr)
                ptr = 0;
            break;

        case instr_dec_ptr:
            if (!ptr--)
                ptr = ptr_max_addr;
            break;
        case instr_inc_val:
            mem[ptr]++;
            break;
        case instr_dec_val:
            mem[ptr]--;
            break;
        case instr_print:
            std::cout << mem[ptr];
            break;
        
        case instr_jmp_r:
            if (!mem[ptr])
            {
                brk = 1;
                break;
            }
            ptr = instr.val + 1;
            if (ptr == ptr_max_addr + 1)
                ptr = 0;
            break;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_progs;
    std::cin >> n_progs;
    std::cin.ignore();
    for (int pn = 1; pn <= n_progs; pn++)
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

            if (pn != n_progs)
                std::fill(mem, mem + mem_size, 0);
        }
        else
            std::cout << "COMPILE ERROR\n";
    }
}