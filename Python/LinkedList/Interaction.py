from common import *
class Solution:
    #2.两数相加
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        cur = vhead = ListNode(0)
        while l1 or l2:
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            num = (a+b+carry) % 10
            carry = (a+b+carry) // 10
            cur.next = ListNode(num)

            cur = cur.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        if carry:
            cur.next = ListNode(carry)

        return vhead.next

    #445.两数相加II
    def addTwoNumbersII(self, l1: ListNode, l2: ListNode) -> ListNode:
        stack1,stack2 = [],[]
        while l1:
            stack1.append(l1.val)
            l1 = l1.next
        while l2:
            stack2.append(l2.val)
            l2 = l2.next

        vhead = ListNode(0)
        carry = 0
        while stack1 or stack2:
            a = stack1.pop() if stack1 else 0
            b = stack2.pop() if stack2 else 0
            num = (a + b + carry) % 10
            carry = (a + b + carry) // 10

            addNode = ListNode(num)
            vhead.next,addNode.next = addNode,vhead.next
        if carry:
            addNode = ListNode(carry)
            vhead.next,addNode.next = addNode,vhead.next

        return vhead.next

    #21.合并两个有序链表
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur = vhead = ListNode(0)
        while list1 or list2:
            if list1 and list2:
                a = list1.val
                b = list2.val
                if a < b:
                    cur.next = ListNode(a)
                    list1 = list1.next
                else:
                    cur.next = ListNode(b)
                    list2 = list2.next
            else:
                if list1:
                    cur.next = ListNode(list1.val)
                    list1 = list1.next
                else:
                    cur.next = ListNode(list2.val)
                    list2 = list2.next
            cur = cur.next
        return vhead.next

    #23.合并K个升序链表
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        minHeap = []
        for list in lists:
            while list:
                heapq.heappush(minHeap,list.val)
                list = list.next
        cur = vhead = ListNode(0)
        while minHeap:
            cur.next = ListNode(heapq.heappop(minHeap))
            cur = cur.next
        return vhead.next

    #160.相交链表
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        curA = headA
        curB = headB
        while curA != curB:
            curA = curA.next if curA else headB
            curB = curB.next if curB else headA

        return curA

    #1669.合并两个链表
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        cur = list1
        idx = 0
        while idx < a-1:
            cur = cur.next
            idx += 1
        l = cur
        while idx < b+1:
            cur = cur.next
            idx += 1
        r = cur

        l.next = list2
        tmp = list2
        while tmp.next:
            tmp = tmp.next
        tmp.next = r

        return list1

l1 = create_linked_list([9,9,9,9,9,9,9])
l2 = create_linked_list([9,9,9,9])
s = Solution()
resHead = s.addTwoNumbers(l1,l2)
print_linked_list(resHead)

l1 = create_linked_list([5])
l2 = create_linked_list([5])
s = Solution()
resHead = s.addTwoNumbersII(l1,l2)
print_linked_list(resHead)

l1 = create_linked_list([1,2,4])
l2 = create_linked_list([1,3,4])
s = Solution()
resHead = s.mergeTwoLists(l1,l2)
print_linked_list(resHead)

l1 = create_linked_list([1,4,5])
l2 = create_linked_list([1,3,4])
l3 = create_linked_list([2,6])
s = Solution()
resHead = s.mergeKLists([l1,l2,l3])
print_linked_list(resHead)