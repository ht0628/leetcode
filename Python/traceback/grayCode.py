from typing import *

class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = []
        path = []
        used = [0] * (2**n)
        def isValid(val1, val2):
            s1 = bin(val1)
            s2 = bin(val2)
            cnt = 0


        def traceback(used):
            if len(res):
                return

            if len(path) == n:
                if isValid(path[0], path[-1]):
                    res.append(path)
                return

            for i in range(2**n):
                if used[i]: continue
                if isValid(i,path[-1]):
                    path.append(i)
                    used[i] = 1
                    traceback(used)
                    path.pop()
                    used[i] = 0
