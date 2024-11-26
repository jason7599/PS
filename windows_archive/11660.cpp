#include <iostream>

int main() {
    int size, n;
    std::cin >> size >> n;

    int **myGraph = new int*[size+1];

    for(int i=0; i<=size; i++) {
        myGraph[i]=new int[size+1];
        myGraph[0][i]=0;
        myGraph[i][0]=0;
    }

    for(int row=1; row<=size; row++)
        for(int col=1; col<=size; col++) {
            std::cin>>myGraph[row][col];
            myGraph[row][col]+=myGraph[row-1][col]+myGraph[row][col-1]-myGraph[row-1][col-1];
        }

    int startRow, startCol, endRow, endCol;
    for(int i=0; i<n; i++) {
        std::cin>>startRow>>startCol>>endRow>>endCol;
        std::cout<<myGraph[endRow][endCol]-myGraph[startRow-1][endCol]-myGraph[endRow][startCol-1]+myGraph[startRow-1][startCol-1];
        std::cout<<std::endl;
    }
}
