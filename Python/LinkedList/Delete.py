from common import *

class Solution:
    #203. 移除链表元素
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        cur = vhead = ListNode(next=head)
        while cur:
            if cur.next and cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return vhead.next
    def removeElements1(self, head: ListNode, val: int) -> ListNode:
        cur = vhead = ListNode(next=head)
        while cur.next:
            if cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return vhead.next

    #19.删除链表的倒数第N个结点
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        slow = fast = vhead = ListNode(next=head)
        for _ in range(n):
            fast = fast.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return vhead.next

    #237. 删除链表中的节点
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next

    #2095. 删除链表的中间节点
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = vhead = ListNode(next=head)
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        slow.next = slow.next.next
        return vhead.next

    #82.删除排序链表中的重复元素II
    def deleteDuplicates2(self, head: ListNode) -> ListNode:
        pre = vhead = ListNode(next=head)
        cur = head
        while(cur):
            #先判断cur.next可以避免cur.next.val处报错
            #循环完成后取得重复的最后一个节点
            while cur.next and cur.val == cur.next.val:
                cur = cur.next
            if pre.next == cur:
                pre = pre.next
            else:
                pre.next = cur.next
            cur = cur.next
        return vhead.next

    #83.删除排序链表中的重复元素
    def deleteDuplicates1(self, head: ListNode) -> ListNode:
        cur = vhead = ListNode(val=-101, next=head)
        while(cur):
            if cur.next and cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return vhead.next

    #1171.从链表中删去总和值为零的连续节点
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        from collections import defaultdict
        preSum = defaultdict(ListNode)
        cur=vhead = ListNode(0,next=head)
        tmp = 0
        while cur:
            tmp += cur.val
            preSum[tmp] = cur
            cur = cur.next
        tmp = 0
        cur = vhead
        while cur:
            tmp += cur.val
            cur.next = preSum[tmp].next
            cur = cur.next
        return vhead.next


head = create_linked_list([1,2,3,4,5])
s = Solution()
resHead = s.removeElements(head,2)
print_linked_list(resHead)

head = create_linked_list([1,2,3,4,5])
s = Solution()
resHead = s.removeElements1(head,2)
print_linked_list(resHead)

head = create_linked_list([1,2,3,4,5])
s = Solution()
resHead = s.removeNthFromEnd(head,2)
print_linked_list(resHead)

head = create_linked_list([1,2,3])
s = Solution()
resHead = s.deleteMiddle(head)
print_linked_list(resHead)

head = create_linked_list([1,1])
s = Solution()
resHead = s.deleteDuplicates2(head)
print_linked_list(resHead)

head = create_linked_list([1,1])
s = Solution()
resHead = s.deleteDuplicates1(head)
print_linked_list(resHead)

head = create_linked_list([1,2,-3,3,1])
s = Solution()
resHead = s.removeZeroSumSublists(head)
print_linked_list(resHead)
