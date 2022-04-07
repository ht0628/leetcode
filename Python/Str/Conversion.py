class Solution:
    #6.Z字形变换
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        res = [""] * numRows
        resIdx = 0
        flag = -1
        for c in s:
            res[resIdx] += c
            if resIdx == 0 or resIdx == numRows-1:
                flag = -flag
            resIdx += flag
        tmp = ""
        for i in res:
            tmp += i
        return tmp

    #7.整数反转
    def reverse(self, x: int) -> int:
        res = 0
        if x<0: sign = -1
        else: sign = 1
        while(x):
            if res > (2**31 - 1) / 10 or res < -2**31 / 10:
                return 0
            tmp = abs(x) % 10
            x = abs(x) // 10
            res = res * 10 + sign*tmp
        return res

    #8.字符串转换整数(atoi)
    def myAtoi(self, s: str) -> int:
        def delFrontSpace(s):
            i = 0
            while i<len(s) and s[i] == " ":
                i+=1
            return s[i:]

        def extractNum(s):
            if not s:
                return 0
            sign = 1
            if s[0] == "-":
                sign = -1
                s = s[1:]
            elif s[0] == "+":
                sign = 1
                s = s[1:]
            num = 0
            for i in range(len(s)):
                if s[i].isdigit():
                    num = num*10+int(s[i])
                else:
                    break
            num *= sign
            if num > 2 ** 31 - 1:
                num = 2 ** 31 - 1
            elif num < -2 ** 31:
                num = -2 ** 31
            return num

        s = delFrontSpace(s)
        num = extractNum(s)

        return num

    #9.回文数
    def isPalindrome(self, x: int) -> bool:
        origin = x
        res = 0
        if x<0:
            return False
        else:
            while x:
                pop = x % 10
                x = x // 10
                res = res * 10 + pop
        return res == origin

    #12.整数转罗马数字
    def intToRoman(self, num: int) -> str:
        res = ''
        d = {'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,
             'L':50,'XL':40,'X':10,'IX':9,'V':5,'IV':4,'I':1}
        for key in d.keys():
            cnt = num // d[key]
            if cnt != 0:
                res += key * cnt
            num = num % d[key]
        return res

    #13.罗马数字转整数
    def romanToInt(self, s: str) -> int:
        res = 0
        d = {'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,
             'L':50,'XL':40,'X':10,'IX':9,'V':5,'IV':4,'I':1}
        i = 0
        while(i<len(s)):
            if s[i:i+2] in d:
                res += d[s[i:i+2]]
                i += 2
            else:
                res += d[s[i]]
                i += 1
        return res


s = Solution()
res = s.convert("PAYPALISHIRING",3)
print(res)

res = s.reverse(-321)
print(res)

num = s.myAtoi('')
print(num)

res = s.isPalindrome(121)
print(res)

res = s.intToRoman(1994)
print(res)

res = s.romanToInt("MCMXCIV")
print(res)