class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        if(head->next==head)
            return head;
        ListNode * slow=head, *fast=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow && fast&&fast->next && slow!=fast);
        
        if(!slow || !fast || !fast->next)
            return NULL;
        slow=head;
        if(slow==fast)
            return slow;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow->next;
    }
};