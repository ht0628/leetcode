from typing import *
from collections import defaultdict

class Trie:
    def __init__(self):
        self.children = defaultdict(Trie)
        self.word = ''

    def insert(self, word):
        cur = self
        for w in word:
           cur = cur.children[w]
        cur.word = word


class Solution:
    #79.单词搜索
    def exist(self, board: List[List[str]], word: str) -> bool:
        dirs = [[0,1],[0,-1],[1,0],[-1,0]]
        m,n = len(board),len(board[0])
        used = [[0] * n for _ in range(m)]

        def traceback(row, col, idx):
            if idx == len(word):
                return True
            for dir in dirs:
                curRow = row + dir[0]
                curCol = col + dir[1]
                if 0 <= curRow < m and 0 <= curCol < n \
                    and board[curRow][curCol] == word[idx] and not used[curRow][curCol]:
                    used[curRow][curCol] = 1
                    if traceback(curRow, curCol, idx + 1): return True
                    used[curRow][curCol] = 0
            return False

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    used[i][j] = 1
                    if traceback(i, j, 1): return True
                    used[i][j] = 0
        return False

    #130.被围绕的区域
    def solve(self, board: List[List[str]]) -> None:
        m,n = len(board), len(board[0])
        def dfs(i, j):
            if not 0 <= i < m or not 0 <= j < n or board[i][j] != 'O':
                return
            board[i][j] = 'A'
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j-1)
            dfs(i, j+1)
        for i in range(m):
            dfs(i, 0)
            dfs(i, n-1)
        for j in range(n):
            dfs(0, j)
            dfs(m-1, j)
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'A':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] ='X'

    #200.岛屿数量
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        used = [[0] * n for _ in range(m)]
        res = 0

        def dfs(i, j, used):
            if 0 <= i < m and 0 <= j < n and not used[i][j] and grid[i][j] == '1':
                used[i][j] = 1
                dfs(i+1, j, used)
                dfs(i-1, j, used)
                dfs(i, j-1, used)
                dfs(i, j+1, used)

        for i in range(m):
            for j in range(n):
                if not used[i][j] and grid[i][j] == "1":
                    dfs(i, j, used)
                    res += 1
        return res

    #212.单词搜索2
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # 建立前缀树
        trie = {}
        for word in words:
            node = trie  # 头节点
            for w in word:
                node = node.setdefault(w, {})
            node['end'] = 1
        # print(trie)

        res = []

        def dfs(r, c, trie, s):
            letter = board[r][c]
            # 定位到有letter的那颗树
            trie = trie[letter]
            if 'end' in trie and trie['end'] == 1:
                res.append(s + letter)
                trie['end'] = 0  # 标志位，遍历到该路径终止时剪枝
            board[r][c] = '#'  # 将遍历过的单元格标为#，确保在同一个单词中不被重复使用
            for x, y in ([r - 1, c], [r + 1, c], [r, c - 1], [r, c + 1]):
                if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] in trie:
                    dfs(x, y, trie, s + letter)
            board[r][c] = letter  # 该单词结束，将board复原

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] in trie:
                    dfs(i, j, trie, '')
        return res

    def findWords2(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.insert(word)
        dirs = [[0,1],[0,-1],[1,0],[-1,0]]
        m,n = len(board),len(board[0])
        used = [[0] * n for _ in range(m)]
        res = []

        def traceback(i, j, used, trie):
            if trie.word != '':
                res.append(trie.word)
                trie.word = ''
            for dir in dirs:
                curI = i + dir[0]
                curJ = j + dir[1]
                if 0 <= curI < m and 0 <= curJ < n \
                    and not used[curI][curJ] and board[curI][curJ] in trie.children:
                    used[curI][curJ] = 1
                    traceback(curI, curJ, used, trie.children[board[curI][curJ]])
                    used[curI][curJ] = 0
            return

        for i in range(m):
            for j in range(n):
                if board[i][j] in trie.children:
                    used[i][j] = 1
                    traceback(i, j, used, trie.children[board[i][j]])
                    used[i][j] = 0
        return res


s = Solution()
res = s.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED")
print(res)

board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
s.solve(board)
print(board)

grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
res = s.numIslands(grid)
print(res)

board = [["o","a","b","n"],["o","t","a","e"],["a","h","k","r"],["a","f","l","v"]]
words = ["oa","oaa"]
res = s.findWords2(board,words)
print(res)

