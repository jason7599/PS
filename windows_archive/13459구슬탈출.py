class Coord:
    def __init__(self, y:int, x:int):
        self.y = y
        self.x = x
    def __eq__(self, other):
        return isinstance(other, Coord) and self.y == other.y and self.x == other.x


