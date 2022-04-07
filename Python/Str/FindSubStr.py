from typing import *

class Solution:
    #3.无重复字符的最长子串
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        maxLenth = 0
        record = set()

        for right in range(len(s)):
            while s[right] in record:
                record.remove(s[left])
                left += 1
            record.add(s[right])
            maxLenth = max(maxLenth,right-left+1)

        return maxLenth

    #5.最长回文子串
    #中心扩散法
    def longestPalindrome(self, s: str) -> str:
        res = ''

        if len(s) < 2:
            return s
        def expand(left, right):
            while left >=0 and right <= len(s)-1 and s[left]==s[right]:
                left -= 1
                right += 1
            return s[left+1:right]
        for i in range(len(s)):
            s1 = expand(i,i)
            s2 = expand(i,i+1)
            tmp = s1 if len(s1)>len(s2) else s2
            res = tmp if len(tmp)>len(res) else res
        return res
    #动态规划
    def longestPalindrome1(self, s: str) -> str:
        n = len(s)
        if n <= 1:
            return s
        maxLenth = 0
        res = s[0]
        dp = [[False] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
        for j in range(1,n):
            for i in range(j):
                if j - i < 3:
                    dp[i][j] = s[i]==s[j]
                else:
                    dp[i][j] = dp[i+1][j-1] and s[i]==s[j]
                if dp[i][j]:
                    if j-i+1>maxLenth:
                        maxLenth = j-i+1
                        res = s[i:j+1]
        return res

    #76.最小覆盖字串
    def minWindow(self, s: str, t: str) -> str:
        left = 0
        record = dict()
        res = s + '0'
        count = len(t)
        for c in t:
            record[c] = record.get(c,0) + 1

        for right,c in enumerate(s):
            if c in record:
                record[c] -= 1
                count = count - 1 if record[c] >= 0 else count
            while not count:
                if s[left] in record:
                    record[s[left]] += 1
                    if record[s[left]] > 0:
                        count += 1
                        res = s[left:right+1] if (right-left+1) < len(res) else res
                left += 1
        return res if len(res) != len(s) + 1 else ''

    #187.重复的DNA序列
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) < 10:
            return []
        n = len(s)
        d = dict()
        res = []
        for i in range(n-9):
            tmp = s[i:i+10]
            d[tmp] = d.get(tmp,0) + 1
            if d[tmp] == 2:
                res.append(tmp)
        return res



s = Solution()
res = s.lengthOfLongestSubstring('abcabcbb')
print(res)

res = s.longestPalindrome("babad")
print(res)
res = s.longestPalindrome1("ac")
print(res)

res = s.minWindow("ADOBECODEBANC","ABC")
print(res)

res = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")
print(res)