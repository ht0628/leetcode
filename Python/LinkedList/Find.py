from common import *

class Solution:
    #725.分隔列表
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        lenth = 0
        cur = head
        while cur:
            cur = cur.next
            lenth += 1
        basic = lenth // k
        remain = lenth % k
        res = [None] * k
        pre = ListNode(next=head)
        cur = head
        index = 0
        while cur:
            res[index] = cur
            tmpLenth = basic + 1 if index<remain else basic
            while tmpLenth:
                pre,cur = cur,cur.next
                tmpLenth -= 1
            pre.next = None
            index += 1

        return res

    #817.链表组件
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        nums = set(nums)
        cur = head
        res = 0

        while cur:
            if cur.val in nums:
                res += 1
                while cur.next and cur.next.val in nums:
                    cur = cur.next
            cur = cur.next
        return res

    #876.链表的中间节点
    def middleNode(self, head: ListNode) -> ListNode:
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow

    #1019.链表中的下一个更大节点
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        cur = head
        list = []
        while cur:
            list.append(cur.val)
            cur = cur.next

        res = [0] * len(list)
        stack = []

        for i,val in enumerate(list):
            while stack and list[stack[-1]] < val:
                index = stack.pop()
                res[index] = val
            stack.append(i)

        return res

    #2058.找出临界点之间的最小和最大距离
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        list = []
        cur = head
        while cur:
            list.append(cur.val)
            cur = cur.next

        limitP = []
        for i in range(1,len(list)-1):
            if list[i-1] < list[i] and list[i] > list[i+1]:
                limitP.append(i)
            elif list[i-1] > list[i] and list[i] < list[i+1]:
                limitP.append(i)

        if len(limitP) < 2:
            return [-1,-1]
        maxDis = limitP[-1] - limitP[0]
        minDis = limitP[1] - limitP[0]
        for i in range(1,len(limitP)-1):
            minDis = min(minDis,limitP[i+1]-limitP[i])

        return [minDis,maxDis]

    #2130.链表最大孪生和
    #空间复杂度为O(n)
    def pairSum(self, head: Optional[ListNode]) -> int:
        l1 = []
        cur = head
        while cur:
            l1.append(cur.val)
            cur = cur.next
        l2 = l1[::-1]
        l3 = [i + j for i,j in zip(l1,l2)]
        return max(l3)
    #空间复杂度为O(1)
    def pairSum1(self, head: Optional[ListNode]) -> int:
        fast = slow = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        r = slow.next
        slow.next = None

        pre,cur = None,r
        while cur:
            cur.next,pre,cur = pre,cur,cur.next
        r = pre

        res = 0
        cur = head
        while cur and r:
            res = max(res,cur.val + r.val)
            cur = cur.next
            r = r.next
        return res



head = create_linked_list([1,2,3])
k = 5
s = Solution()
resHead = s.splitListToParts(head,k)
for i in resHead:
    print_linked_list(i)

head = create_linked_list([0,1,2,3])
nums = [0,1,3]
s = Solution()
res = s.numComponents(head,nums)
print(res)

head = create_linked_list([1,2,3,4,5,6])
s = Solution()
resHead = s.middleNode(head)
print_linked_list(resHead)

head = create_linked_list([2,7,4,3,5])
s = Solution()
res = s.nextLargerNodes(head)
print(res)

head = create_linked_list([6,8,4,1,9,6,6,10,6])
s = Solution()
res = s.nodesBetweenCriticalPoints(head)
print(res)

head = create_linked_list([5,4,2,1])
s = Solution()
res = s.pairSum(head)
print(res)
res = s.pairSum1(head)
print(res)