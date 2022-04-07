from typing import *

class Solution:
    #78.子集
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res,path = [],[]
        def traceback(nums, idx):
            res.append(path[:])
            for i in range(idx, len(nums)):
                path.append(nums[i])
                traceback(nums, i+1)
                path.pop()
        traceback(nums, 0)
        return res

    #90.子集II
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res,path = [],[]
        nums.sort()
        def traceback(nums, idx):
            res.append(path[:])
            for i in range(idx, len(nums)):
                if i > idx and nums[i] == nums[i-1]:
                    continue
                path.append(nums[i])
                traceback(nums, i+1)
                path.pop()
        traceback(nums,0)
        return res

s = Solution()
res = s.subsets([1,2,3])
print(res)

res = s.subsetsWithDup([1,2,2])
print(res)
