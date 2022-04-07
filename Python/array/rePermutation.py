from typing import *

class Solution:
    #31.下一个排列
    def nextPermutation(self, nums: List[int]) -> None:
        for i in range(len(nums)-1, 0, -1):
            if nums[i-1] < nums[i]:
                for j in range(len(nums)-1, i-1, -1):
                    if nums[j] > nums[i-1]:
                        nums[i-1],nums[j] = nums[j],nums[i-1]
                        L,R = i,len(nums)-1
                        while L < R:
                            nums[L],nums[R] = nums[R],nums[L]
                            L += 1
                            R -= 1
                        return
        nums.reverse()

    #33.搜索旋转排序数组
    def search(self, nums: List[int], target: int) -> int:


s = Solution()
nums = [3,2,1]
s.nextPermutation(nums)
print(nums)