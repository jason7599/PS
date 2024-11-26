#include <iostream>
#include <string>
#include <queue>

using namespace std;

int solve(const string& start_num, int swap_count)
{
    queue<string> q;

    // visited[stoi(start_num)] = true;
    q.push(start_num);

    int digits = start_num.length();
    int max_val = -1;

    int swapped = 0;
    int q_size;
    while ((q_size = q.size()) && swap_count--)
    {
        bool visited[1'000'001] = {false};
        while (q_size--)
        {
            string num = q.front();
            q.pop();

            for (int i = 0; i < digits - 1; i++)
            {
                for (int j = i + 1; j < digits; j++)
                {
                    if (i == 0 && num[j] == '0')
                        continue;

                    if (num[i] == num[j])
                    {
                        if (max_val < stoi(num))
                            max_val = stoi(num);
                        continue;
                    }
                    
                    string cpy = num;

                    char temp = cpy[j];
                    cpy[j] = num[i];
                    cpy[i] = temp;

                    int num_i = stoi(cpy);

                    if (!swap_count)
                    {
                        if (max_val < num_i)
                            max_val = num_i;
                    }
                    else if (!visited[num_i])
                    {
                        visited[num_i] = true;
                        q.push(cpy);
                    }
                }
            }
        }
    }

    return max_val;
}

int main()
{
    string num; int swap_count;
    cin >> num >> swap_count;
    cout << solve(num, swap_count) << '\n';
}