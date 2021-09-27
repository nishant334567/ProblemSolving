class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0,s=0;
        ListNode* prev,*head;
        head=l2;
        while(l1 && l2)
        {
            s = l2->val+l1->val+c;
            c = s/10;
            l2->val = s%10;
            l1 = l1->next;
            if(!l2->next)
                prev = l2;
            l2 = l2->next;
        }
        if(!l1 && !l2 && c==1)
        {
            prev->next = new ListNode(1);
            return head;
        }
        if(!l2)
            prev->next = l1;
        while(l1)
        {
            s = l1->val+c;
            l1->val = s%10;
            c = s/10;
            if(!l1->next && c==1){
                l1->next = new ListNode(1);
                c=0;
            }
            l1 = l1->next;
        }
        while(l2)
        {
            s = l2->val+c;
            l2->val = s%10;
            c = s/10;
            if(!l2->next && c==1){
                l2->next = new ListNode(1);
                c=0;
            }
             l2=l2->next;
        }
            
        return head;
        
    }
};