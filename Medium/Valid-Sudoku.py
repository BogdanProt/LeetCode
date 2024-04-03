class Solution(object):
    def isValidSudoku(self, board):
        cols = defaultdict(set)
        rows = defaultdict(set)
        squares = defaultdict(set) # key = (row/3 , column/3)

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if (board[r][c] in rows[r] or board[r][c] in cols[c] or board[r][c] in squares[(r//3, c//3)]):
                    # If we've seen this value in the current row/column/square that we are in
                    return False
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[(r//3, c//3)].add(board[r][c])
        return True

# Hashset for columns, rows and squares. For the current element in the board, I check whether it is in any of those. If yes, return False. Else, add the current element to the dicts of each row, column and square.
        