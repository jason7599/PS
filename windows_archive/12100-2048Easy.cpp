#include <iostream>

using namespace std;

int boardSize;
int board[20][20];
bool mergedAlready[20][20];
int maxBlock;

void shiftLeft();
void shiftRight();
void shiftUp();
void shiftDown();

void brute(int n) {
    if(n==5) {
        for(int i=0; i<boardSize; i++) {
            for(int j=0; j<boardSize; j++) {
                if(board[i][j] > maxBlock)
                    maxBlock = board[i][j];
            }
        }
        return;
    }

    int board_cpy[20][20];
    for(int i=0; i<boardSize; i++)
        for(int j=0; j<boardSize; j++)
            board_cpy[i][j]=board[i][j];

    for(int k=0; k<4; k++) 
    {
        if(k==0)      shiftLeft();
        else if(k==1) shiftRight();
        else if(k==2) shiftUp();
        else          shiftDown();

        brute(n+1);

        for(int i=0; i<boardSize; i++)
            for(int j=0; j<boardSize; j++)
                board[i][j]=board_cpy[i][j];
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

    cin>>boardSize;

    for(int i=0; i<boardSize; i++) {
        for(int j=0; j<boardSize; j++) {
            cin>>board[i][j];
        }
    }

    brute(0);
    cout<<maxBlock;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void shiftLeft() {
    for(int i=0; i<boardSize; i++)
        for(int j=0; j<boardSize; j++)
            mergedAlready[i][j]=false;

    for(int col=1; col<boardSize; col++) {
        for(int row=0; row<boardSize; row++) {
            int cur = board[row][col]; 
            if(!cur) continue;

            int hitPos = col-1;
            while(hitPos>=0 && board[row][hitPos]== 0) {
                hitPos--;
            }

            board[row][col]=0;
            // if(cur==2) cout<<"hitPos: "<<hitPos<<endl;

            if(hitPos<0) {
                board[row][0] = cur;
            }
            else if(board[row][hitPos]==cur && !mergedAlready[row][hitPos]) {
                board[row][hitPos] = cur*2;
                mergedAlready[row][hitPos]=true;
            }
            else {
                board[row][hitPos+1] = cur;
            }
            // if(hitPos+1 != col)
        }
    }
}

void shiftRight() {
    for(int i=0; i<boardSize; i++)
        for(int j=0; j<boardSize; j++)
            mergedAlready[i][j]=false;

    for(int col = boardSize-2; col>=0; col--) {
        for(int row=0; row<boardSize; row++) {
            int cur = board[row][col]; 
            if(!cur) continue;

            int hitPos = col + 1;
            while(hitPos<boardSize && board[row][hitPos]== 0) {
                hitPos++;
            }

            board[row][col]=0;

            if(hitPos==boardSize) {
                board[row][boardSize-1] = cur;
            }
            else if(board[row][hitPos]==cur && !mergedAlready[row][hitPos]) {
                board[row][hitPos] = cur*2;
                mergedAlready[row][hitPos] = true;
            }
            else {
                board[row][hitPos-1] = cur;
            }
        }
    }
}

void shiftDown() {
    for(int i=0; i<boardSize; i++)
        for(int j=0; j<boardSize; j++)
            mergedAlready[i][j]=false;

    for(int row = boardSize-2; row>=0; row--) {
        for(int col=0; col<boardSize; col++) {
            int cur = board[row][col]; 
            if(!cur) continue;

            int hitPos = row + 1;
            while(hitPos<boardSize && board[hitPos][col]== 0) {
                hitPos++;
            }

            board[row][col]=0;

            if(hitPos==boardSize) {
                board[boardSize-1][col] = cur;
            }
            else if(board[hitPos][col]==cur && !mergedAlready[hitPos][col]) {
                board[hitPos][col] = cur*2;
                mergedAlready[hitPos][col] = true;
            }
            else {
                board[hitPos-1][col] = cur;
            }
        }
    }
}

void shiftUp() {
    for(int i=0; i<boardSize; i++)
        for(int j=0; j<boardSize; j++)
            mergedAlready[i][j]=false;

    for(int row=1; row<boardSize; row++) {
        for(int col=0; col<boardSize; col++) {
            int cur = board[row][col]; 
            if(!cur) continue;

            int hitPos = row-1;
            while(hitPos>=0 && board[hitPos][col]== 0) {
                hitPos--;
            }

            board[row][col]=0;

            if(hitPos<0) {
                board[0][col] = cur;
            }
            else if(board[hitPos][col]==cur && !mergedAlready[hitPos][col]) {
                board[hitPos][col] = cur*2;
                mergedAlready[hitPos][col] = true;
            }
            else {
                board[hitPos+1][col] = cur;
            }
        }
    }
}
