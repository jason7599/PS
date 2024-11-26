#include <iostream>

using namespace std;

bool matrixA[50][50];
bool matrixB[50][50];

int main() {

    int sizeX, sizeY;
    cin>>sizeX>>sizeY;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            matrixA[i][j] = temp=='1';
        }
    }
    
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            matrixB[i][j] = temp=='1';
        }
    }

    int count = 0;

    for(int i=0; i<=sizeX-3; i++) {
        for(int j=0; j<=sizeY-3; j++) {
            if(matrixA[i][j] != matrixB[i][j]) {
                count++;
                for(int x=i; x<i+3; x++) {
                    for(int y=j; y<j+3; y++) {
                        matrixA[x][y] = !matrixA[x][y];
                    }
                }
            }
        }
    }

    for(int i=sizeX-1; i>=0; i--) {
        for(int j=sizeY-1; j>=0; j--) {
            if(matrixA[i][j] != matrixB[i][j]) {
                cout<<-1;
                return 0;
            }
        }
    }

    cout<<count;
}