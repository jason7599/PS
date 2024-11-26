#include <iostream>

using namespace std;

/*
start에서 계속 merge 시키는 느낌?
단계적으로. 거리 1000 안되면 
*/

struct coord 
{
    int x, y;
};

coord input_coord()
{
    int x, y;
    cin >> x >> y;
    return coord{x, y};
}

int main()
{
    int num_store;
    cin >> num_store;

    coord start_coord = input_coord();
}