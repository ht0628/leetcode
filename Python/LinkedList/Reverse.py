from common import *

class Solution:
    # 206.反转链表
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        cur = head
        while cur:
            cur.next,pre,cur = pre,cur,cur.next
        return pre

    # 92.反转链表II
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        ##头插法 ———— 将数据一个一个往头前丢，造成头不断地后移。
        vhead = ListNode(next = head)
        #确定头前的位置
        pre = vhead
        for _ in range(left-1):
            pre = pre.next
        #确定头的位置
        cur = pre.next
        for _ in range(right - left):
            #确定头后要丢的节点，由于头是不断移动的，所以这个也要实时更新。
            removed = cur.next
            pre.next,cur.next,removed.next = removed,removed.next,pre.next
        return vhead.next

    def reverseBetween2(self, head: ListNode, left: int, right: int) -> ListNode:
        ##拼接法
        cur = vhead = ListNode(next = head)
        #找到left前的节点
        for _ in range(left-1):
            cur = cur.next
        pre = cur
        #找到right处的节点切断并记录right后的节点
        for _ in range(right - left + 1):
            cur = cur.next
        cur.next,succ = None,cur.next
        #翻转部分链表
        rhead = self.reverseList(pre.next)
        pre.next.next,pre.next = succ,rhead
        return vhead.next

    #25.K个一组翻转链表
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(head):
            pre,cur = None,head
            while cur:
                cur.next, pre, cur = pre, cur, cur.next
                #pre, cur, cur.next = cur, cur.next, pre
            return pre
        pre = cur = vhead = ListNode(next=head)
        while True:
            #找到第k个节点
            for _ in range(k):
                if cur: cur = cur.next
            if not cur: break

            cur.next,succ = None,cur.next #断开+找右侧点
            left = pre.next #找到原反转头
            reverseHead = reverse(left) #反转
            pre.next,left.next = reverseHead,succ #重连（左测点连到新反转头上 && 原反转头连到右侧点上）
            cur = pre = left #更新左侧点和即将移动的寻找右侧点标的

        return vhead.next

    #2074.反转偶数长度组的节点
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        L = []
        cur = head
        while(cur):
            L.append(cur.val)
            cur = cur.next
        tmpLenth = 0
        i = 0
        n = len(L)
        while i<len(L):
            tmpLenth += 1
            if i+tmpLenth > n:
                tmpLenth = n-i
            if tmpLenth % 2 == 0:
                L[i:i+tmpLenth] = L[i:i+tmpLenth][::-1]
            i += tmpLenth

        cur = vhead = ListNode(0)
        for i in L:
            cur.next = ListNode(i)
            cur = cur.next
        return vhead.next


head = create_linked_list([1,2,3,4,5])
k = 2
s = Solution()
resHead = s.reverseKGroup(head,k)
print_linked_list(resHead)

head = create_linked_list([5,2,6,3,9,1,7,3,8,4])
s = Solution()
resHead = s.reverseEvenLengthGroups(head)
print_linked_list(resHead)