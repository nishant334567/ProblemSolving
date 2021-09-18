class Solution {
public:
    ListNode* reverse(ListNode *head)
    {
        ListNode* prev = NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* s=head,*f=head->next;
        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
        }
        if(f)
            s=s->next;
        s=reverse(s);
        f=head;
        while(s)
        {
            if(f->val!=s->val)
                return false;
            f=f->next;
            s=s->next;
        }
        return true;
        
        
    }
};