#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using pip = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_lectures;
    cin >> num_lectures;

    vector<pip> lectures;

    while (num_lectures--)
    {
        int start, finish;
        cin >> start >> start >> finish;
        lectures.push_back({start, finish});
    }

    sort(lectures.begin(), lectures.end());

    int num_req_classes = 0;
    
    while (!lectures.empty())
    {
        




        num_req_classes++;
    }

    cout << num_req_classes;
    
    return 0;
}