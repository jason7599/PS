#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // top = 가장 작은 양수
priority_queue<int> nq; // top = 가장 큰 음수

void push(int x)
{
    if (x > 0)
        pq.push(x);
    else
        nq.push(x);
}

int pop()
{
    if (pq.empty())
    {
        if (nq.empty())
            return 0;
        
        int t = nq.top();
        nq.pop();
        return t;
    }

    if (nq.empty())
    {
        int t = pq.top();
        pq.pop();
        return t;
    }

    if (pq.top() >= -nq.top())
    {
        int t = nq.top();
        nq.pop();
        return t;
    }
    
    int t = pq.top();
    pq.pop();
    return t;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        if (x)
            push(x);
        else
            cout << pop() << '\n';
    }
    return 0;
}