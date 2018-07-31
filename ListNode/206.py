# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        new_head = ListNode(None)
        p = head
        tmp_node = None
        while(p):
            tmp_node = p.next
            p.next = new_head.next
            new_head.next = p
            p = tmp_node
        return new_head.next
