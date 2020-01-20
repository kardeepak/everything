
class KakuroSolver(object):
    """
    This class solves a kakuro puzzle of any dimensions.
    Example:
    kakuro_solver = KakuroSolver(10, 10)
    kakuro_solver[1,1] = 3
    kakuro_solver[1,4] = 5
    kakuro_solver[2,3] = (14, 17)
    ...
    ...
    kakuro_solver[7,8] = 9
    Calling `sudoku_solver.solve()` will return a solved kakuro grid.
    """

    def __init__(self, rows, columns):
        self._grid = [[0 for _ in range(columns)] for _ in range(rows)]
        self._rows = rows
        self._columns = columns
    
    def __getitem__(self, index):
        row, column = index
        return self._grid[row - 1][column - 1]
    
    def __setitem__(self, index, value):
        row, column = index
        self._grid[row - 1][column - 1] = value
    
    def find_left_sum_cell(self, row, column):
        while not isinstance(self[row, column], tuple):
            column -= 1
            if column <= 0:
                raise Exception("Invalid Grid")
        return row, column

    def find_upper_sum_cell(self, row, column):
        while not isinstance(self[row, column], tuple):
            row -= 1
            if row <= 0:
                raise Exception("Invalid Grid")
        return row, column
    
    def find_possible_values()