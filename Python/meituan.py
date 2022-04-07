## 1.
def c1(val):
    if val % 11 == 0:
        return True
    else:
        return False

def c2(strVal):
    tmp = 0
    for c in strVal:
        if c == '1': tmp += 1
    if tmp >= 2: return True
    else: return False

# n = int(input())
# for _ in range(n):
#     strValue = input()
#     intValue = int(strValue)
#     if c1(intValue) or c2(strValue):
#         print('yes')
#     else:
#         print('no')

##2. 小美现在有一个序列，序列中仅包含1和-1两种数字。小美现在想要知道，有多少个连续的子序列，序列中的数字乘积为正。
# n = int(input())
# nums = list(map(int,input().split(' ')))
n = 4
nums = [1, 1, -1, -1]
multi = 1
res = 0

def dfs(i, nums, multi):
    global res
    if i > len(nums) - 1: return
    multi = multi*nums[i]
    if multi == 1: res += 1
    dfs(i+1, nums, multi)

# for i in range(n):
#     dfs(i,nums,multi)
# print(res)

##3 做饭




