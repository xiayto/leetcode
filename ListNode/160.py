class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getLength(self, node):
        n = 0
        while node != None:
            n += 1
            node = node.next
        return n
    def moveNode(self, node, n):
        while n > 0:
            n -= 1
            node = node.next
        return node
    
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        res = None
        p1 = headA
        p2 = headB
        n1 = self.getLength(p1)
        n2 = self.getLength(p2)
        if n1 > n2 :
            p1 = self.moveNode(p1, n1-n2)
        else:
            p2 = self.moveNode(p2, n2-n1)
        
        while(p1 != None and p2 != None):
            if p1 == p2:
                res = p1
                break
            else:
                p1 = p1.next
                p2 = p2.next
        return res
