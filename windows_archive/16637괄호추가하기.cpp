#include <iostream>

using namespace std;

struct Op
{
    int num;
    char type;
};

int num_ops;
Op ops[10];

int max_val = 1 << 31;

int eval(int x, int y, char type)
{
    switch (type)
    {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        default: 
        cout << "fuck"; return -1;
    }
}

void func(int op_index, int res)
{
    if (op_index >= num_ops)
    {
        if (res > max_val)
            max_val = res;

        return;
    }

    Op this_op = ops[op_index];

    // case 1: no parenthesis, only calc this op and move on to next idx
    func(op_index + 1, eval(res, this_op.num, this_op.type));

    // case 2: parenthesis, calc next op first and this op and advance 2 indices
    if (op_index + 1 < num_ops)
    {
        Op next_op = ops[op_index + 1];
        int paren_val = eval(this_op.num, next_op.num, next_op.type);
        func(op_index + 2, eval(res, paren_val, this_op.type));
    }

}

int main()
{
    int eq_len;
    cin >> eq_len;

    num_ops = eq_len / 2 + 1;

    for (int i = 0; i < num_ops; i++)
    {
        char type, num_c;

        if (i) cin >> type;
        else type = '+'; // implicit leading +
        
        cin >> num_c;

        ops[i] = Op{num_c - '0', type};
    }

    func(0, 0);

    cout << max_val;
}