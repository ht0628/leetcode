from typing import  *

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res,path = [],[]
        used = [0] * len(nums)
        def traceback(nums):
            if len(path) == len(nums):
                res.append(path[:])
                return
            for i in range(len(nums)):
                if used[i]: continue
                if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                    continue
                used[i] = 1
                path.append(nums[i])
                traceback(nums)
                path.pop()
                used[i] = 0
        traceback(nums)
        return res

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res,path = [],[]
        nums.sort()
        used = [0] * len(nums)
        def traceback(nums):
            if len(path) == len(nums):
                res.append(path[:])
                return
            for i in range(len(nums)):
                if used[i]: continue
                if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                    continue
                used[i] = 1
                path.append(nums[i])
                traceback(nums)
                path.pop()
                used[i] = 0
        traceback(nums)
        return res

s = Solution()
res = s.permute([1,2,3])
print(res)

res = s.permuteUnique([3,3,0,3])
print(res)