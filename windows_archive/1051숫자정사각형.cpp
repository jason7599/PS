#include <iostream>

using namespace std;

int sizeX, sizeY;
int board[50][50];

int main() {
    cin>>sizeX>>sizeY;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            board[i][j] = temp -'0';
        }
    }

    int maxSize = sizeX > sizeY ? sizeY : sizeX;

    while(true) {
        for(int x=0; x<=sizeX-maxSize; x++) {
            for(int y=0; y<=sizeY-maxSize; y++) {
                if(board[x][y] == board[x+maxSize-1][y]
                && board[x][y] == board[x][y+maxSize-1]
                && board[x][y] == board[x+maxSize-1][y+maxSize-1]) {
                    cout<<maxSize * maxSize;
                    return 0;
                }
            }
        }
        maxSize--;
    }
}