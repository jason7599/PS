#include <iostream>
#include <vector>

using namespace std;

struct Testcase
{
    vector<int> sales;
    vector<vector<int>> links;
    int ans;
};

vector<Testcase> testcases =
{
    {
        {14, 17, 15, 18, 19, 14, 13, 16, 28, 17},
        {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}},
        44
    },
    {
        {5, 6, 5, 3, 4},
        {{2,3}, {1,4}, {2,5}, {1,2}},
        6
    },
    {
        {5, 6, 5, 1, 4,},
        {{2, 3}, {1, 4}, {2, 5}, {1, 2}},
        5
    },
    {
        {10, 10, 1, 1},
        {{3, 2}, {4, 3}, {1, 4}},
        2
    }
};

int solution(vector<int> sales, vector<vector<int>> links)
{
    

    return 0;
}

int main()
{
    for (int i = 0; i < testcases.size(); i++)
    {
        int my_ans = solution(testcases[i].sales, testcases[i].links);
        cout << "TC " << i + 1 << ": ";    
        if (my_ans == testcases[i].ans)
            cout << "Passed\n";
        else
        {
            cout << "Failed; Expected " << testcases[i].ans << ", got " << my_ans << '\n';
            break;
        }
    }

    return 0;
}