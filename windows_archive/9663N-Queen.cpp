#include <iostream>
#include <string>

using namespace std;

int n, ans;
bool queen[15][15]; // true if queen is placed
bool notAvailable[15][15];
int queensPlaced, tilesRemaining;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void func(int prevX, int prevY);
void placeQueen(int x, int y);
void printBoard();

int main() {

    cin >> n;
    // tilesRemaining = n * n;

    func(0, -1);

    cout << ans;
    
}

void func(int prevX, int prevY) {

    // not possible
    // if(n - queensPlaced > tilesRemaining) return;

    // done
    if(queensPlaced == n) {
        ans++;
        // cout<<"prevX: "<<prevX<<", prevY: "<<prevY<<'\n';
        printBoard();
        return;
    }

    if(prevX == n) return;

    // finish off remaining columns
    for(int y = prevY + 1; y < n; y++) {

        tilesRemaining--;
        func(prevX, y); // without placing queen
        tilesRemaining++;

        if(!queen[prevX][y] && !notAvailable[prevX][y]) { // place queen

            bool copy[15][15];
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    copy[i][j] = notAvailable[i][j];

            int temp = tilesRemaining;
            placeQueen(prevX, y);

            func(prevX + 1, -1); // skip entire row
            tilesRemaining = temp;

            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    notAvailable[i][j] = copy[i][j];

            queen[prevX][y] = false;
            queensPlaced--;
        }

    }

    for(int x = prevX + 1; x < n; x++) {
        for(int y = 0; y < n; y ++) {

            tilesRemaining--;
            func(x, y); // without placing queen
            tilesRemaining++;

            if(!queen[x][y] && !notAvailable[x][y]) { // place queen

                bool copy[15][15];
                for(int i=0; i<n; i++)
                    for(int j=0; j<n; j++)
                        copy[i][j] = notAvailable[i][j];

                int temp = tilesRemaining;
                placeQueen(x, y);

                func(x + 1, -1); // skip entire row
                tilesRemaining = temp;

                for(int i=0; i<n; i++)
                    for(int j=0; j<n; j++)
                        notAvailable[i][j] = copy[i][j];

                queen[x][y] = false;
                queensPlaced--;

            }

        }
    }

}

void placeQueen(int x, int y) {

    // cout<<"placeQueen("<<x<<", "<<y<<");";

    queen[x][y] = true;
    queensPlaced++;

    int range = 1;

    while (true) {

        bool finished = true;

        for(int k = 0; k < 8; k++) { // probably not the best way to do this

            int nx = x + dx[k] * range;
            int ny = y + dy[k] * range;

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if(!notAvailable[nx][ny]) tilesRemaining--;
            notAvailable[nx][ny] = true;
            finished = false;
        }

        if(finished) {
            // printBoard();
            return;
        }

        range++;
    }
}

void printBoard() {
    cout << "\n<BOARD>\n";
    cout << "tilesRemaining: " << tilesRemaining <<'\n';
    cout << "queensPlaced: " << queensPlaced << '\n';
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(queen[i][j]) cout << 'Q';
            else if(notAvailable[i][j]) cout << 'x';
            else cout << '_';
        }
        cout<<'\n';
    }
}

