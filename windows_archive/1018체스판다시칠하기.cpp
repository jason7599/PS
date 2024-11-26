#include <iostream>
#include <algorithm>

using namespace std;

char board[50][50];

int sizeX, sizeY;

int main() {
    
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            cin>>board[i][j];
        }
    }

    int ans = 50*50;

    for(int i=0; i<=sizeX-8; i++) {
        for(int j=0; j<=sizeY-8; j++) {
            int toBlack = 0;
            int toWhite = 0;
            char target = 'B';
            for(int x=i; x<i+8; x++) {
                for(int y=j; y<j+8; y++) {
                    if(board[x][y] != target) toBlack++;
                    else toWhite++;
                    if(target == 'B') target = 'W';
                    else target = 'B';
                }
                if(target == 'B') target = 'W';
                else target = 'B';
            }
            ans = min({ans, toWhite, toBlack});
        }
    }

    cout<<ans;
}
