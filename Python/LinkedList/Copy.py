from  common import *

class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head: return head
        #建立节点映射字典，但还未建立复制链表的连接关系。
        d = defaultdict(Node)
        cur = head
        while cur:
            d[cur] = Node(cur.val)
            cur = cur.next

        cur = head
        while cur:
            if cur.next:d[cur].next = d[cur.next]
            else:d[cur].next=None
            if cur.random:d[cur].random = d[cur.random]
            else:d[cur.random]=None
            cur = cur.next
        return d[head]



