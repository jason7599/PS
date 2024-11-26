class Direction:
    EAST = 1;
    WEST = 2;
    NORTH = 3;
    SOUTH = 4;

MAP: list[list[int]] = [];
MAP_SIZE_X: int;
MAP_SIZE_Y: int;

DX = [None, 0, 0, -1, 1];
DY = [None, 1, -1, 0, 0];

class Dice:
    def __init__(self, x = 0, y = 0):
        self.top = 0;
        self.east = 0;
        self.west = 0;
        self.north = 0;
        self.south = 0;
        self.bottom = 0;
        self.x = x;
        self.y = y;

    def roll(self, direction: Direction):
        global MAP;

        nx = self.x + DX[direction];
        ny = self.y + DY[direction];

        if nx < 0 or nx == MAP_SIZE_X or ny < 0 or ny == MAP_SIZE_Y: return;

        if direction == Direction.EAST:
            self.west, self.top, self.east, self.bottom = self.bottom, self.west, self.top, self.east;
        elif direction == Direction.WEST:
            self.west, self.top, self.east, self.bottom = self.top, self.east, self.bottom, self.west;
        elif direction == Direction.NORTH:
            self.top, self.north, self.bottom, self.south = self.south, self.top, self.north, self.bottom;
        else:
            self.top, self.north, self.bottom, self.south = self.north, self.bottom, self.south, self.top;
        
        if MAP[nx][ny]:
            self.bottom = MAP[nx][ny];
            MAP[nx][ny] = 0;
        else: 
            MAP[nx][ny] = self.bottom;

        self.x = nx;
        self.y = ny;

        print(self.top);

    def __str__(self):
        res = "  " + str(self.top) + '\n';
        res += str(self.west) + ' ';
        res += str(self.south) + ' ';
        res += str(self.east) + ' ';
        res += str(self.north) + ' ';
        res += "\n  " + str(self.bottom);
        return res;

def main():
    global MAP, MAP_SIZE_X, MAP_SIZE_Y;
    
    MAP_SIZE_X, MAP_SIZE_Y, startX, startY, moveCount = map(int, input().split());

    for x in range(MAP_SIZE_X):
        MAP.append(list(map(int, input().split())));
    
    myDice = Dice(startX, startY);
    directionList = list(map(int, input().split()));

    for direction in directionList:
        myDice.roll(direction);

main();
