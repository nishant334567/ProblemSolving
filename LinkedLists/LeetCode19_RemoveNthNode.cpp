/* -----------------------------  19. Remove Nth Node From End of List ----------------------------------------

Given the head of a linked list, remove the nth node from the end of the list and return its head. */

/* Explanation

    Brute will have worse case of O(2n)
    To do it in 1 pass, we have to take 2 pointers (ptr1 & ptr2)
    move one of them (say ptr1), go n distance with it, reamaining will be (L-n) distance


    now ptr1, traverse this remaining (L-n) distance with you friend (ptr2) whom you left at the head
    When ptr1 will cover remaining (L-n) IT WILL BE AT END, and ptr2 will be at L-n from beginning which is
    n from end

    Give it a thought.
    */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)
            return NULL;
       ListNode* p1, *p2,*temp;
        p1=head;
        p2=head;
        while(n--)
            p1=p1->next;
        if(!p1)
            return head->next;
        p1=p1->next;
        while(p1!=NULL)
        {
            p1=p1->next;
            p2=p2->next;
        }
        temp=p2->next;
        p2->next=p2->next->next;
        delete(temp);
        return head;
    }
};