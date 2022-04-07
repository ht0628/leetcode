from typing import *
from collections import defaultdict

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#将传入的数组转化为链表
def create_linked_list(arr):
    if len(arr) == 0:
        return None

    head = ListNode(arr[0])
    cur = head
    for i in range(1, len(arr)):
        cur.next = ListNode(arr[i])
        cur = cur.next
    return head

#传入链表头节点，以数组形式返回
def print_linked_list(head):
    cur = head
    res = []
    while cur:
        res.append(cur.val)
        cur = cur.next
    print(res)
