
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        def printNode(self, a):
            curr = self
            while(curr):
                a.append(curr.val)
                curr = curr.next
        a = [];
        b = [];
        c = [];
        k = 0;
        l = 0;
        printNode(l1, a);
        printNode(l2, b);

        if(len(a) > len(b)):
            l = len(b)

        elif(len(b) > len(a)):
            l = len(a)

        else:
            l = len(a)

        for i in range(l):

            if((a[i]+b[i] < 10)and(k == 0)):
                c.append(a[i]+b[i])
            elif(a[i]+b[i] >= 10):
                c.append((a[i]+b[i])-10)
                k = 1
            elif(k == 1):
                c.append(a[i]+b[i]+1)
                k = 0

        if(len(c) < len(a)):
            if(k == 0):
                for i in range(len(c), len(a)):
                    c.append(a[i])
            else:
                for i in range(len(c), len(a)):
                    if(i == len(c)):
                        c.append(a[i]+1)

        elif(len(c) < len(b)):
            if(k == 0):
                for i in range(len(c), len(b)):
                    c.append(b[i])
            else:
                for i in range(len(c), len(b)):
                    if(i==len(c)):
                        c.append(b[i]+1)
        
        else:
            if(k==1):
                c.append(1)
            
            
                    
           

        
        return(c)
        
       
    
       
