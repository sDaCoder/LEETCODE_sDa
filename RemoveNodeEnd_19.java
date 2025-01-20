class Solution {
    public void append(int val, ListNode head, ListNode tail)
    {
        ListNode ptr = new ListNode(val);

        if (head == null)
        {
            head = ptr;
            tail = ptr;
        }

        else
        {
            tail.next = ptr;
            tail = ptr;
        }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode ptr = head, ptrn = head;
        while(ptr != null && ptrn != null)
        {
            ptr = ptr.next;
            for (int i = 0; i < n; i++) {
                ptrn = ptrn.next;
            }
        }
        return ptr;
    }
    void printList(ListNode head)
    {
        ListNode ptr = head;
    
        while (ptr != null)
        {
            System.out.print(ptr.val + " ");
            ptr = ptr.next;
        }
        System.out.println();
    }
}


public class RemoveNodeEnd_19 {
    public static void main(String[] args) {
        Solution S = new Solution();

        ListNode h = null;
        ListNode t = null;

        int nodes[] = {1,2,3,4,5};

        for (int i : nodes) {
            S.append(i, h, t);
        }

        S.printList(h);
    }
}