from common import *

class Solution:
    #61.旋转列表
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head: return head

        lenth = 0
        cur = head
        while cur:
            cur = cur.next
            lenth += 1
        target = k % lenth
        if target == 0: return head
        #寻找倒数第k+1个节点
        slow = fast = head
        while target:
            fast = fast.next
            target -= 1
        #此时fast在第k+1个节点处,slow未动还在第一个节点处。
        while fast.next:
            fast = fast.next
            slow = slow.next
        #此时slow到达了倒数k+1的位置
        newHead = slow.next
        slow.next = None
        fast.next = head
        return newHead
    def rotateRight2(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head: return head

        lenth = 0
        cur = head
        while cur:
            cur = cur.next
            lenth += 1
        target = k % lenth
        if target == 0: return head
        #寻找倒数第k+1个节点
        slow = fast = vhead = ListNode(next=head)
        while target:
            fast = fast.next
            target -= 1
        #此时fast在第k个节点处,slow未动还在第0个节点处。
        while fast.next:
            fast = fast.next
            slow = slow.next
        #此时fast到了末尾节点,slow到达了倒数k+1的位置。
        fast.next = vhead.next
        vhead.next = slow.next
        slow.next = None
        return vhead.next

    #86.分隔链表
    def partition(self, head: ListNode, x: int) -> ListNode:
        cur = vhead = ListNode(next=head)
        tmpHead = tmp = ListNode(0)
        while cur:
            if cur.next and cur.next.val < x:
                tmp.next = ListNode(cur.next.val)
                tmp = tmp.next
                cur.next = cur.next.next
            else:
                cur = cur.next
        tmp.next = vhead.next
        return tmpHead.next

    #143.重排链表
    def reorderList(self, head: ListNode) -> ListNode:
        def findMidNode(head):
            slow,fast = head,head
            while fast.next and fast.next.next:
                fast = fast.next.next
                slow = slow.next
            return slow

        def reverse(head):
            pre,cur = None,head
            while cur:
                cur.next,pre,cur = pre,cur,cur.next
            return pre

        midNode = findMidNode(head)
        tail,midNode.next = midNode.next,None
        reverseTail = reverse(tail)

        cur = head
        while reverseTail:
            # tmp = reverseTail.next
            # cur.next,reverseTail.next= reverseTail,cur.next
            # reverseTail = tmp
            # cur = cur.next.next
            # 更清晰的写法
            curNxt = cur.next
            reverseTailNxt = reverseTail.next

            cur.next,reverseTail.next = reverseTail,curNxt

            cur = curNxt
            reverseTail = reverseTailNxt

        return head

    #328.奇偶链表
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head and not head.next: return head
        oddvHead = odd = ListNode(0)
        evenvHead = even = ListNode(0)
        cur = head
        idx = 1
        while cur:
            if idx % 2 == 1:
                odd.next = cur
                odd = odd.next
            else:
                even.next = cur
                even = even.next
            cur = cur.next
            idx += 1
        odd.next = evenvHead.next
        even.next = None
        return oddvHead.next
    def oddEvenList1(self, head: ListNode) -> ListNode:
        if not head: return head
        odd,even = head,head.next
        firstEven = even
        while even and even.next:
            nexOdd = even.next
            nexEven = nexOdd.next

            odd.next = nexOdd
            even.next = nexEven

            odd = odd.next
            even = even.next
        odd.next = firstEven
        return head

    #24.两两交换链表中的节点
    def swapPairs(self, head: ListNode) -> ListNode:
        pre = vhead = ListNode(next = head)
        cur = pre.next
        while cur and cur.next:
            preNxt = cur.next
            curNxt = preNxt.next

            pre.next = preNxt
            preNxt.next = cur
            cur.next = curNxt

            pre = cur
            cur = curNxt
        return vhead.next

    #1721.交换链表中的节点
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        fast = slow = vhead = ListNode(next = head)
        for _ in range(k):
            fast = fast.next
        p = fast
        while fast:
            fast = fast.next
            slow = slow.next
        q = slow
        p.val,q.val = q.val,p.val
        return vhead.next

head = create_linked_list([1,2,3,4,5])
k = 2
s = Solution()
resHead = s.rotateRight(head,k)
print_linked_list(resHead)

head = create_linked_list([1,4,3,2,5,2])
x = 3
s = Solution()
resHead = s.partition(head,x)
print_linked_list(resHead)

head = create_linked_list([1,2,3,4,5])
s = Solution()
resHead = s.reorderList(head)
print_linked_list(resHead)

head = create_linked_list([1,2,3,4,5])
s = Solution()
resHead = s.oddEvenList1(head)
print_linked_list(resHead)

list1 = create_linked_list([0,1,2,3,4,5])
list2 = create_linked_list([1000000,1000001,1000002])
s = Solution()
resHead = s.mergeInBetween(list1,3,4,list2)
print_linked_list(resHead)