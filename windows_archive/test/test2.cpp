#include <iostream>

using namespace std;

class Dude
{
public:
    void hi();
};

class HiDude : public Dude
{
public:
    void hi() override
    {
        cout << 1;
    }
};

int main()
{
    HiDude hi;
    hi.hi();

    int a = 1e3;
    cout << a;
}