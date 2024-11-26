class Direction:
    def __init__(self, rowDelta: int, colDelta: int):
        self.rowDelta = rowDelta
        self.colDelta = colDelta

UP = Direction(-1, 0)
RIGHT = Direction(0, 1)
DOWN = Direction(1, 0)
LEFT = Direction(0, -1)

DIRECTIONS = [UP, RIGHT, DOWN]

class Block:
    def __init__(self, char: str):
        self.char = char