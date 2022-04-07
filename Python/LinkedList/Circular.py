from common import *

class Solution:
    #141.环形链表
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False

    #142.环形链表II
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                cur = head
                while cur != slow:
                    cur = cur.next
                    slow = slow.next
                return cur

        return None