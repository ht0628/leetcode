from typing import *

class Solution:
    #22.括号生成
    ##动态规划
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for _ in range(n+1)]
        for i in range(n+1):
            if i == 0: dp[i] = ['']
            elif i == 1: dp[i] = ['()']
            else:
                for j in range(i):
                    p,q = dp[j],dp[i-j-1]
                    for x in p:
                        for y in q:
                            dp[i].append('(' + x + ')' + y)
        return dp[n]
    ##常规回溯法
    def generateParenthesis1(self, n: int) -> List[str]:
        #建立存储结果的列表
        res = []
        #建立存储路径的列表
        path = []

        def traceback(path, left, right):
            #1.剪支操作 直接返回不记录数据
            if left > n or right < left:
                return

            #2.符合条件直接返回
            if len(path) == 2*n:
                #注意此处append必须是路径的深拷贝
                res.append(''.join(path[:]))
                return

            #3.深度遍历
            #3.1 列出选择列表
            for i in ['(',')']:
                path.append(i)
                if i == '(':
                    traceback(path, left + 1, right)
                    path.pop()
                else:
                    traceback(path, left, right + 1)
                    path.pop()

        traceback(path,0,0)

        return res






s = Solution()
res = s.generateParenthesis(3)
print(res)

res = s.generateParenthesis1(3)
print(res)

