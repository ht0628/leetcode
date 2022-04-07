from typing import *

class Solution:
    #14.最长公共前缀
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        for tmp in zip(*strs):
            s = set(tmp)
            if len(s) == 1:
                res += list(s)[0]
            else:
                break
        return res
    def longestCommonPrefix1(self, strs: List[str]) -> str:
        res = ''
        for i in range(len(strs[0])):
            for j in range(len(strs) - 1):
                if i > len(strs[j]) - 1 or i > len(strs[j+1]) - 1 or strs[j][i] != strs[j+1][i]:
                    return res
            res += strs[0][i]
        return res

    #30.串联所有单词的子串
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        cnt = len(words)
        lenth = len(words[0])
        winLenth = cnt * lenth
        d = dict()
        for i in words:
            d[i] = d.get(i,0) + 1
        res = []
        for i in range(len(s) - winLenth + 1):
            r = {}
            winS = s[i:i+winLenth]
            for j in range(cnt):
                tmp = winS[lenth*j:lenth*(j+1)]
                if tmp not in d:
                    break
                r[tmp] = r.get(tmp,0) + 1
                if r[tmp] > d[tmp]:
                    break
            else:
                res.append(i)
        return res

    #415.字符串相加
    def addStrings(self, num1: str, num2: str) -> str:
        i,j,carry = len(num1)-1,len(num2)-1,0
        res = ""

        while i >= 0 or j >=0 or carry:
            a = int(num1[i]) if i >= 0 else 0
            b = int(num2[j]) if j >= 0 else 0
            tmp = (a + b + carry) % 10
            carry = (a + b + carry) // 10
            res = str(tmp) + res
            i,j = i-1,j-1

        return res

    #43.字符串相乘
    def multiply(self, num1: str, num2: str) -> str:
        def multiplyUnit(num1, num2_unit):
            carry,i = 0,len(num1)-1
            res = ''
            while(i >= 0 or carry):
                a = int(num1[i]) if i >= 0 else 0
                tmp = a * int(num2_unit) + carry
                carry = tmp // 10
                remainder = tmp % 10
                res = str(remainder) + res
                i -= 1
            return res

        def add(num1, num2):
            i, j, carry = len(num1) - 1, len(num2) - 1, 0
            res = ""

            while i >= 0 or j >= 0 or carry:
                a = int(num1[i]) if i >= 0 else 0
                b = int(num2[j]) if j >= 0 else 0
                tmp = (a + b + carry) % 10
                carry = (a + b + carry) // 10
                res = str(tmp) + res
                i, j = i - 1, j - 1

            return res

        if num1 == '0' or num2 == '0':
            return '0'
        elif num1 == '1' or num2 == '1':
            return num1 if num2 == '1' else num2

        i = len(num2) - 1
        multiplyRes = []
        res = '0'
        while(i >= 0):
            tmp = multiplyUnit(num1, num2[i])
            multiplyRes.append(tmp + '0'*(len(num2) - i - 1))
            i -= 1
        for i in range(len(multiplyRes)):
            res = add(res,multiplyRes[i])
        return res
    def multiply1(self, num1: str, num2: str) -> str:
        res = 0
        for i,v in enumerate(num1[::-1]):
            for j,u in enumerate(num2[::-1]):
                res += int(v) * int(u) * (10 ** (i+j))
        return str(res)

    #67.二进制求和
    def addBinary(self, a: str, b: str) -> str:
        a = a[::-1]
        b = b[::-1]
        res = ''
        i,j,carry = 0,0,0
        while i < len(a) or j < len(b) or carry:
            x = int(a[i]) if i < len(a) else 0
            y = int(b[i]) if i < len(b) else 0
            tmp = x + y + carry
            remainder = tmp % 2
            carry = tmp // 2
            res = str(remainder) + res
            i += 1
            j += 1
        return res
    def addBinary1(self, a: str, b: str) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        return bin(x)[2:]

    #49.字母异位词分组
    ##暴力
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = []
        res = []
        from collections import Counter
        for i in range(len(strs)):
            tmp = Counter(strs[i])
            if tmp not in d:
                d.append(tmp)
                res.append([strs[i]])
            else:
                idx = d.index(tmp)
                res[idx].append(strs[i])
        return res
    ##排序
    def groupAnagrams1(self, strs: List[str]) -> List[List[str]]:
        record = dict()
        res = []
        idx = 0
        for s in strs:
            tmp = ''.join(sorted(s))
            if tmp not in record:
                record[tmp] = idx
                res.append([s])
                idx += 1
            else:
                res[record[tmp]].append(s)
        return res



s = Solution()
res = s.longestCommonPrefix(["flower","flow","flight"])
print(res)
res = s.longestCommonPrefix1(["flower","flow","flight"])
print(res)

res = s.findSubstring("wordgoodgoodgoodbestword",["word","good","best","good"])
print(res)

res = s.addStrings("11","123")
print(res)

res = s.multiply('123','456')
print(res)

res = s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
print(res)
res = s.groupAnagrams1(["eat", "tea", "tan", "ate", "nat", "bat"])
print(res)

res = s.addBinary("1010","1011")
print(res)
res = s.addBinary1("1010","1011")
print(res)

