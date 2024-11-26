#include <iostream>

using namespace std;    

int map[50][50];
bool cleaned[50][50];

int dRow[] = {-1,0,1,0};
int dCol[] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    int curRow, curCol;
    cin>>curRow>>curCol;

    int curDir; cin>>curDir;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>map[i][j];
        
    int count=0;
    int turnCount=0;

    // cout<<"Start!\n";
    while(true) {
        // cout<<"I'm at ["<<curRow<<"]["<<curCol<<"] now.\n";
        if(!cleaned[curRow][curCol]) {
            // cout<<"["<<curRow<<"]["<<curCol<<"] isn't cleaned yet. Let me fix that!\n";
            cleaned[curRow][curCol]=true;
            count++;
        }
        int leftDir = (curDir+3)%4;
        int leftRow = curRow+dRow[leftDir];
        int leftCol = curCol+dCol[leftDir];
        // cout<<"Looking at ["<<leftRow<<"]["<<leftCol<<"]..\n";
        curDir=leftDir; //일단 무조건 왼쪽으로 돌테니까
        turnCount++;
        if(map[leftRow][leftCol]==0 && !cleaned[leftRow][leftCol]) { //case 2-1: not yet cleaned
            // cout<<"["<<leftRow<<"]["<<leftCol<<"] isn't cleaned yet. Let me fix that!\n";
            curCol=leftCol; curRow=leftRow;
            cleaned[curRow][curCol]=true;
            count++;
            turnCount=0;
        }
        if(turnCount==4) {
            int backRow = curRow-dRow[curDir];
            int backCol = curCol-dCol[curDir];
            if(map[backRow][backCol]==1) { //case 2-4
                break;
            }
            curRow=backRow; curCol=backCol;
            turnCount=0;
        }
    }

    cout<<count;
}