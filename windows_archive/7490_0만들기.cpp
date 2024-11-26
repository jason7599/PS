#include <iostream>

using namespace std;

int seq_len; // 3 <= seq_len <= 9
char ops[8]; // n_ops = seq_len - 1.

const char plus_op = '+';
const char minus_op = '-';
const char concat_op = ' ';

int eval_ops();

void func(int op_idx)
{
    if (op_idx == seq_len - 1)
    {
        if (eval_ops() == 0)
        {
            printf("1");
            for (int num = 2; num <= seq_len; num++)
            {
                printf("%c%d", ops[num - 2], num);
            }
            printf("\n");
        }
        return;
    }

    ops[op_idx] = concat_op;
    func(op_idx + 1);

    ops[op_idx] = plus_op;
    func(op_idx + 1);

    ops[op_idx] = minus_op;
    func(op_idx + 1);
}

int eval_ops()
{
    int res = 0;
    int hold_val = 1;
    char hold_op = plus_op;

    for (int num = 2; num <= seq_len; num++)
    {
        char op = ops[num - 2];

        if (op == concat_op)
        {
            hold_val = hold_val * 10 + num;
        }
        else
        {
            if (hold_op == plus_op)
            {
                res += hold_val;
            }
            else if (hold_op == minus_op)
            {
                res -= hold_val;
            }

            hold_op = op;
            hold_val = num;
        }
    }

    if (hold_op == plus_op)
    {
        res += hold_val;
    }
    else if (hold_op == minus_op)
    {
        res -= hold_val;
    }

    return res;
}

int main()
{
    int num_input;
    scanf("%d", &num_input);

    while (num_input--)
    {
        scanf("%d", &seq_len);
        func(0);
        printf("\n");
    }
}