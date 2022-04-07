class Solution:
    #1.给你一个整数数组 nums ，请在时间复杂度为O(n) 下找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积
    def GetSubArrayMaxProduct(self, nums):
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]

        for i in range(1, n):
            if dp[i - 1] == 0:
                dp[i] = nums[i]
            else:
                dp[i] = dp[i - 1] * nums[i]
        print(dp)
        return max(max(dp), max(nums))

    #2.用户账单逾期扣分
    def calDPDScore(self, dpdInfo):
        maxDpdLevel = 0
        layTime = 0
        for dpd in dpdInfo:
            if dpd == 'Y':
                layTime += 1
                if 0<layTime<=3:
                    maxDpdLevel = max(maxDpdLevel,1)
                elif 3<layTime<=7:
                    maxDpdLevel = max(maxDpdLevel,2)
                else:
                    maxDpdLevel = max(maxDpdLevel,3)
            elif dpd == 'N':
                layTime = 0
        if maxDpdLevel == 1: return -10
        elif maxDpdLevel == 2: return -15
        elif maxDpdLevel == 3: return -25
        else: return 0

    #3.最少计算次数 (10,100)->(22,202)
    def GetMinCalculateCount(self, sourceX, sourceY, targetX, targetY):
        #不可能往小了变
        if targetX < sourceX or targetY < sourceY:
            print('error1')
            return -1

        #差值一定成整数倍
        targetDiff = targetY - targetX
        sourceDiff = sourceY - sourceX
        tmp = targetDiff / sourceDiff
        tmp1 = targetDiff // sourceDiff
        if tmp - tmp1 != 0 or tmp < 1:
            print('error2')
            return -1

        #计算乘数的次数
        multiNum = 0
        cur = tmp1
        while cur:
            if cur == 1:
                break
            if cur % 2 == 0:
                multiNum += 1
                cur = cur / 2
            else:
                print('error3')
                return -1
        print('multiNum=',multiNum)

        #计算加法次数
        addNum = 0
        sourceX *= tmp1
        sourceY *= tmp1
        XDiff = targetX - sourceX
        YDiff = targetY - sourceY
        if XDiff != YDiff:
            print('error4')
            return -1
        else:
            b = bin(XDiff)
            for idx,i in enumerate(b[2:][::-1]):
                if i == '1' and idx <= multiNum:
                    addNum += 1
                elif i =='1' and idx > multiNum:
                    addNum += (2**idx) // (2**multiNum)

        print('addNum=',addNum)

        res = addNum + multiNum
        return res




nums = [1,3,-2,4,0,-1]
s = Solution()
res = s.GetSubArrayMaxProduct(nums)
print(res)

dpd = "NNYYYYYNNYY"
res = s.calDPDScore(dpd)
print(res)

x = (1,2,6,8)
res = s.GetMinCalculateCount(*x)
print(res)