from typing import *
class Solution:
    #11.盛水最多的容器
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        L,R = 0,n-1
        S = 0
        while L < R:
            S = max((R-L) * min(height[R],height[L]),S)
            if height[L] < height[R]:
                L += 1
            else:
                R -= 1
        return S

    #42.接雨水
    #1.按列分析
    def trap(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        for i in range(1, n-1):
            leftMax = max(height[:i])
            rightMax = max(height[i+1:])
            cur = height[i]
            tmp = min(leftMax, rightMax) - cur
            res += tmp if tmp > 0 else 0
        return res

    #2.按列分析优化 - 先求处left/right - 动态规划
    def trap1(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        leftMax = [0] * n
        rightMax = [0] * n
        for i in range(1,n):
            leftMax[i] = max(height[i-1], leftMax[i-1])
        for i in range(n-2, -1, -1):
            rightMax[i] = max(height[i+1], rightMax[i+1])
        for i in range(1,n-1):
            cur = height[i]
            tmp = min(leftMax[i], rightMax[i]) - cur
            res += tmp if tmp > 0 else 0
        return res

    #3.优化动态规划 -> 双指针
    def trap2(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        L,R = 0,n-1
        leftMax,rightMax = 0,0
        while(L < R - 1):
            leftMax = max(leftMax, height[L])
            rightMax = max(rightMax, height[R])
            if leftMax < rightMax:
                tmp = leftMax - height[L+1]
                res += tmp if tmp > 0 else 0
                L += 1
            else:
                tmp = rightMax - height[R-1]
                res += tmp if tmp > 0 else 0
                R -= 1
        return res

    #4.单调栈
    def trap3(self, height: List[int]) -> int:
        n = len(height)
        stack = []
        res = 0
        for i in range(n):
            #如果right高于bottom，即stack[-1]，则表示出现了坑。
            while stack and height[i] > height[stack[-1]]:
                #把坑弹出来一个
                bottom = stack.pop()
                #如果空了表示没有左墙了，这种情况是无法计算的。
                if not stack: break
                #坑高是左墙高度和右墙高度的较小值，
                rightHeight = height[i]
                leftHeight = height[stack[-1]]
                bottomHeight = height[bottom]
                h = min(leftHeight,rightHeight) - bottomHeight
                w = i - stack[-1] - 1
                res += h*w
            stack.append(i)
        return res

s = Solution()
res = s.maxArea([1,8,6,2,5,4,8,3,7])
print(res)

res = s.trap([4,2,0,3,2,5])
print(res)
res = s.trap1([4,2,0,3,2,5])
print(res)
res = s.trap2([4,2,0,3,2,5])
print(res)
res = s.trap3([4,2,0,3,2,5])
print(res)