from typing import *

class Solution:
    #77.组合
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, path = [], []
        """
        tracback参数组成：固定参数 + 变参
        """
        def traceback(n, k, startIdx):
            # 1.剪支
            ##此处无法剪支，支被移动到横向遍历处。
            # 2.返回条件
            if len(path) == k:
                res.append(path[:])
                return
            # 3.遍历
            ##3.1横向遍历选一
            for i in range(startIdx, n - (k - len(path))+ 2):
                ##3.2添加路径值
                path.append(i)
                ##3.3深度遍历到底
                traceback(n, k, i + 1)
                ##3.4回溯
                path.pop()
        traceback(n, k, 1)
        return res

    #17.电话号码的字母组合
    ##常规push/pop回溯
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        res,path = [],[]
        d = {2:"abc",3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"}
        t = []
        for c in digits:
            t.append(d[int(c)])

        def traceback(idx):
            #1.返回
            if len(path) == len(t):
                res.append(''.join(path[:]))
                return
            #2.遍历
            for c in t[idx]:
                path.append(c)
                traceback(idx+1)
                path.pop()

        traceback(0)
        return res
    ##dfs隐藏回溯
    def letterCombinations1(self, digits: str) -> List[str]:
        if not digits:
            return []
        res = []
        d = {2:"abc",3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"}
        t = []
        for c in digits:
            t.append(d[int(c)])

        def dfs(idx, path):
            if len(path) == len(t):
                res.append(path)
                return
            for c in t[idx]:
                dfs(idx+1, path+c)

        dfs(0,'')
        return res

    #22.括号生成
    ##dfs隐藏回溯
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def dfs(n, left, right, path):
            if left > n or right > left:
                return

            if len(path) == 2*n:
                res.append(path)
                return

            for c in "()":
                if c == '(': dfs(n, left+1, right, path+'(')
                else: dfs(n, left, right+1, path+')')

        dfs(n,0,0,'')
        return res
    ##push/pop回溯
    def generateParenthesis1(self, n: int) -> List[str]:
        res,path = [],[]
        def traceback(n, left, right):
            if left > n or right > left:
                return
            if len(path) == 2*n:
                res.append(''.join(path))
                return
            for c in "()":
                path.append(c)
                if c == '(': traceback(n, left+1, right)
                else: traceback(n, left, right+1)
                path.pop()
        traceback(n,0,0)
        return res

    #39.组合总和
    ##常规
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res,path = [],[]
        candidates = sorted(candidates)
        target = target
        def traceback(sum=0, startIdx=0):
            if sum == target:
                res.append(path[:])
                return
            for i in range(startIdx, len(candidates)):
                if sum + candidates[i] > target:
                    return
                path.append(candidates[i])
                traceback(sum+candidates[i], i)
                path.pop()
        traceback()
        return res
    ##dfs-全隐藏即全用deepcopy做传参
    def combinationSum1(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def dfs(path, target, candidates):
            if target == 0:
                res.append(path)
                return
            for i in range(len(candidates)):
                if target >= candidates[i]:
                    dfs(path[:] + [candidates[i]], target-candidates[i], candidates[i:])
                else:
                    return

        dfs([], target, sorted(candidates))
        return res

    #40.组合总和2
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res,path = [],[]
        candidates = sorted(candidates)
        target = target

        def traceback(idx=0, sum=0):
            if sum == target:
                res.append(path[:])
                return
            for i in range(idx, len(candidates)):
                if candidates[i] + sum > target:
                    return
                if i > idx and candidates[i] == candidates[i-1]:
                    continue
                path.append(candidates[i])
                traceback(i+1, sum+candidates[i])
                path.pop()
        traceback()
        return res

    #216.组合总和3
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res,path = [],[]
        def traceback(k=k, n=n, sum=0, idx=1):
            if len(path) == k:
                if sum == n:
                    res.append(path[:])
                return
            for i in range(idx, 9-(k-len(path))+2):
                path.append(i)
                traceback(k, n, sum+i, i+1)
                path.pop()
        traceback()
        return res

s = Solution()
res = s.combine(4,2)
print(res)

res = s.letterCombinations("23")
print(res)
res = s.letterCombinations1("23")
print(res)

res = s.generateParenthesis(3)
print(res)
res = s.generateParenthesis1(3)
print(res)

res = s.combinationSum([2,3,6,7],7)
print(res)
res = s.combinationSum1([2,3,6,7],7)
print(res)

res = s.combinationSum2([10,1,2,7,6,1,5],8)
print(res)

res = s.combinationSum3(3,7)
print(res)