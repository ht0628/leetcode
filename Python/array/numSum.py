from typing import *

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        res = []
        for i in range(len(nums)):
            tmp = target - nums[i]
            if tmp not in d:
                d[nums[i]] = i
            else:
                res.append(d[tmp])
                res.append(i)
        return res

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3: return []

        nums.sort()
        res = []
        for i in range(len(nums) - 2):
            if nums[i] > 0: break
            if i > 0 and nums[i] == nums[i-1]: continue

            L,R = i+1,len(nums)-1
            while(L < R):
                sum = nums[i] + nums[L] + nums[R]
                if sum > 0:
                    R -= 1
                elif sum < 0:
                    L += 1
                else:
                    res.append([nums[i],nums[L],nums[R]])
                    #先去重后移动
                    while L < R and nums[L+1] == nums[L]: L += 1
                    while L < R and nums[R-1] == nums[R]: R -= 1
                    L += 1
                    R -= 1
                    #仿C语言地do-while
                    # while True:
                    #     L += 1
                    #     if L >= R or nums[L-1] != nums[L]: break
                    # while True:
                    #     R -= 1
                    #     if L >= R or nums[R+1] != nums[R]: break
        return res

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        dis = float('inf')
        res = 0
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]: continue
            L,R = i+1, len(nums)-1
            while L < R:
                sum = nums[i] + nums[L] + nums[R]
                if abs(sum - target) < dis:
                    dis = abs(sum - target)
                    res = sum
                if dis == 0: return sum
                if sum > target:
                    while L < R and nums[R-1] == nums[R]:
                        R -= 1
                    R -= 1
                elif sum < target:
                    while L < R and nums[L+1] == nums[L]:
                        L += 1
                    L += 1
        return res

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4: return []
        res = []
        nums.sort()

        for i in range(len(nums) - 3):
            if i > 0 and nums[i] == nums[i-1]: continue
            for j in range(i + 1, len(nums) - 2):
                if j > i + 1 and nums[j] == nums[j-1]: continue
                L = j + 1
                R = len(nums) - 1
                while L < R:
                    sum = nums[i] + nums[j] + nums[L] + nums[R]
                    if sum > target:
                        R -= 1
                    elif sum < target:
                        L += 1
                    else:
                        res.append([nums[i], nums[j], nums[L], nums[R]])
                        while L < R and nums[L+1] == nums[L]:
                            L += 1
                        while L < R and nums[R-1] == nums[R]:
                            R -= 1
                        L += 1
                        R -= 1
        return res

    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        for i in range(n):
            if i == 0: dp[i] = nums[i]
            else: dp[i] = max(dp[i-1]+nums[i], nums[i])
        return max(dp)

    def maxSubArray1(self, nums: List[int]) -> int:
        n = len(nums)
        pre = 0
        res = nums[0]
        for i in range(n):
            pre= max(pre+nums[i], nums[i])
            res = max(res, pre)
        return res

    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1, -1):
            digits[i] = (digits[i] + 1) % 10
            if digits[i] != 0:
                return digits
        return [1] + digits

s = Solution()
res = s.twoSum([2,7,11,15],9)
print(res)

res = s.threeSum([1,-1,-1,0])
print(res)

res = s.threeSumClosest([-1,2,1,-4],1)
print(res)

res = s.fourSum([-2,-1,-1,1,1,2,2],0)
print(res)

res = s.maxSubArray([-2,-1])
print(res)