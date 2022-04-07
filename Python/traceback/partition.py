from typing import *

class Solution:
    #131.分割回文串
    def partition(self, s: str) -> List[List[str]]:
        res,path = [],[]
        def traceback(idx, s):
            #idx起始位置，起始位置在len(s)，就不能切割了，应该直接返回。
            if idx >= len(s):
                res.append(path[:])
                return
            for i in range(idx, len(s)):
                #从idx开始不断增大切割长度
                tmp = s[idx:i+1]
                if tmp == tmp[::-1]:
                    #切割出来的符合回文串就加入path,更新idx,然后继续切割。
                    path.append(tmp)
                    traceback(i+1, s)
                    #切完了就后腿回溯
                    path.pop()
        traceback(0,s)
        return res

    #93.复原IP地址
    ##到len(path) == 4的时候才剪支
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) > 12 or len(s) < 4:
            return []
        res,path = [],[]

        def traceback(s, idx):
            if len(path) == 4:
                if idx == len(s):
                    res.append('.'.join(path))
                    # print('res=',res)
                return
            for i in range(idx, min(idx+3,len(s))):
                ##迭代前就进行预判剪支
                if len(s) - i - 1 > 3 * (3 - len(path)) or len(s) - i - 1 < (3 - len(path)):
                    continue
                tmp = s[idx:i+1]
                if not 0 <= int(tmp) <=255: continue
                if tmp[0] == '0' and len(tmp) != 1: continue
                path.append(tmp)
                # print(path)
                traceback(s, i+1)
                path.pop()
        traceback(s,0)
        return res



s = Solution()
res = s.partition("aab")
print(res)

res = s.restoreIpAddresses('101023')
print(res)