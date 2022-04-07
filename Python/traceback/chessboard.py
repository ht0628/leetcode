from typing import *

class Solution:
    #51.N皇后
    #常规解
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        board = [['.'] * n for _ in range(n)]

        def valid(row, col):
            for i in range(row):
                if board[i][col] == 'Q':
                    return False

            i = row - 1
            j = col - 1
            while i >= 0 and j >= 0:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1

            i = row - 1
            j = col + 1
            while i >= 0 and j < len(board):
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j += 1

            return True

        def traceback(n, row):
            if row == n:
                tmp = []
                for b in board:
                    tmp.append(''.join(b))
                res.append(tmp)
                return

            for col in range(n):
                if not valid(row, col):
                    continue
                board[row][col] = 'Q'
                traceback(n, row + 1)
                board[row][col] = '.'

        traceback(n, 0)
        return res
    #python特性
    def solveNQueens1(self, n: int) -> List[List[str]]:
        res = []
        board = [['.']*n for _ in range(n)]
        c = set()
        dia1 = set()
        dia2 = set()

        def traceback(row):
            if row == n:
                tmp = []
                for b in board:
                    tmp.append(''.join(b))
                res.append(tmp)
                return
            for col in range(n):
                if col in c or row - col in dia1 or row + col in dia2:
                    continue
                c.add(col)
                dia1.add(row-col)
                dia2.add(row+col)
                board[row][col] = 'Q'
                traceback(row+1)
                board[row][col] = '.'
                c.remove(col)
                dia1.remove(row-col)
                dia2.remove(row+col)
        traceback(0)
        return res

    #52.N皇后II
    def totalNQueens(self, n: int) -> int:
        res = 0
        board = [['.']*n for _ in range(n)]
        c = set()
        dia1 = set()
        dia2 = set()

        def traceback(row):
            nonlocal res
            if row == n:
                res = res + 1
                return
            for col in range(n):
                if col in c or row - col in dia1 or row + col in dia2:
                    continue
                c.add(col)
                dia1.add(row-col)
                dia2.add(row+col)
                board[row][col] = 'Q'
                traceback(row+1)
                board[row][col] = '.'
                c.remove(col)
                dia1.remove(row-col)
                dia2.remove(row+col)
        traceback(0)
        return res

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def isValid(row,col,val):
            for i in range(9):
                if board[row][i] == str(val):
                    return False
            for j in range(9):
                if board[j][col] == str(val):
                    return False
            startRow = row // 3 * 3
            startCol = col // 3 * 3
            for i in range(startRow, startRow+3):
                for j in range(startCol, startCol+3):
                    if board[i][j] == str(val):
                        return False
            return True

        def traceback():
            for i in range(9):
                for j in range(9):
                    if board[i][j] != '.':
                        continue
                    for k in range(1,10):
                        if isValid(i,j,k):
                            board[i][j] = str(k)
                            if traceback(): return True
                            board[i][j] = '.'
                    return False
            return True
        traceback()


s = Solution()
res = s.solveNQueens(4)
print(res)

res = s.solveNQueens1(4)
print(res)

res = s.totalNQueens(4)
print(res)



