from typing import *

class Solution:
    #26.删除有序数组中的重复项
    def removeDuplicates(self, nums: List[int]) -> int:
        L = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[L]:
                L = L + 1
                nums[L] = nums[i]
        return L + 1

    #27.移除数组
    def removeElement(self, nums: List[int], val: int) -> int:
        L = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[L] = nums[i]
                L += 1
        return L

    #80.删除有序数组重复项2
    def removeDuplicates2(self, nums: List[int]) -> int:
        d = {}
        L = 0
        for i in range(len(nums)):
            if d.get(nums[i],0) < 2:
                d[nums[i]] = d.get(nums[i],0) + 1
                nums[L] = nums[i]
                L += 1
        return L

s = Solution()
res = s.removeDuplicates([1,1,2])
print(res)

res = s.removeElement([3,2,2,3],3)
print(res)

res = s.removeDuplicates2([1,1,1,2,2,3])
print(res)
