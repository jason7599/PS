#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sales, vector<vector<int>> links);

struct TestCase
{
    vector<int> sales;
    vector<vector<int>> links;
    int ans;
};

int main()
{
    vector<TestCase> test_cases = {
        {{14, 17, 15, 18, 19, 14, 13, 16, 28, 17},
        {{10, 8}}}
    };
}

int solution(vector<int> sales, vector<vector<int>> links)
{

}