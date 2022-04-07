from common import *

class Solution:
    #147.插入排序h
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head

        vhead = ListNode(next=head)
        lastSorted = head
        cur = head.next
        while cur:
            if cur.val < lastSorted.val:
                lastSorted.next = cur.next
                curPrev = vhead
                curNxt = vhead.next
                while curNxt.val < cur.val:
                    curPrev = curPrev.next
                    curNxt = curNxt.next
                curPrev.next = cur
                cur.next = curNxt
                cur = lastSorted.next
            else:
                cur = cur.next
                lastSorted = lastSorted.next
        return vhead.next

    #148.排序链表
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 递归终止条件
        if not head or not head.next: return head

        #切分链表
        fast = slow = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        slow.next,mid = None,slow.next

        #递归进行不断地切分
        l,r = self.sortList(head), self.sortList(mid)

        #此处再l,r切分成最小单元后开始执行,主要执行链表有序合并逻辑.
        cur = vhead = ListNode(0)
        while l and r:
            if l.val < r.val:
                cur.next = l
                l = l.next
            else:
                cur.next = r
                r = r.next
            cur = cur.next
        cur.next = l if l else r
        return vhead.next




head = create_linked_list([4,2,1,3])
s = Solution()
resHead = s.insertionSortList(head)
print_linked_list(resHead)

head = create_linked_list([4,2,1,3])
s = Solution()
resHead = s.sortList(head)
print_linked_list(resHead)