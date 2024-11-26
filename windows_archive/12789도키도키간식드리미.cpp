#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_students;
    cin >> num_students;

    stack<int> stack;
    int next_num = 1;

    for (int i = 0; i < num_students; i++)
    {
        while (!stack.empty() && stack.top() == next_num)
        {
            stack.pop();
            next_num++;
        }

        int student;
        cin >> student;

        if (student == next_num)
        {
            next_num++;
        }
        else
        {
            stack.push(student);
        }
    }

    while (!stack.empty() && stack.top() == next_num)
    {
        stack.pop();
        next_num++;
    }

    if (stack.empty())
        cout << "Nice";
    else
        cout << "Sad";

    return 0;
}
