class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode *slow=head,*fast=head,*p=head;
        int n=0;
        while(p)
        {
            p=p->next;
            n++;
        }
        int r = k%n;
        while(r--)
            fast = fast->next;
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};