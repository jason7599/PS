#include <iostream>

using namespace std;

int sizeX, sizeY;
bool isHorizontal[50][50]; // -
bool checked[50][50];

int main() {
    cin>>sizeX>>sizeY;
    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            char temp; cin>>temp;
            isHorizontal[i][j] = temp == '-';
        }
    }

    int total = 0;

    for(int i=0; i<sizeX; i++) {
        for(int j=0; j<sizeY; j++) {
            if(checked[i][j]) continue;
            total++;
            if(isHorizontal[i][j]) {
                for(int h=j; h<sizeY; h++) {
                    if(!isHorizontal[i][h]) break;
                    checked[i][h] = true;
                }
            }
            else {
                for(int v=i; v<sizeX; v++) {
                    if(isHorizontal[v][j]) break;
                    checked[v][j] = true;
                }
            }
        }
    }

    cout<<total;

}