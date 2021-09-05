/* Sort Linked List */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* curr = new ListNode(0);
        ListNode* temp=curr;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        
        if(l1)
        {
            curr->next=l1;
            // l1=l1->next;
        }
        
        if(l2)
        {
            curr->next=l2;
            // l2=l2->next;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        // vector<int>v;
        // if(!head_)
        //     return NULL;
        // ListNode* head=head_;
        // while(head)
        // {
        //     v.push_back(head->val);
        //     head=head->next;
        // }
        // sort(v.begin(),v.end());
        // head=head_;
        // for(int i=0;i<v.size();i++)
        // {
        //     // cout<<v[i]<<" ";
        //     head->val=v[i];
        //     head=head->next;
        // }
        // return head_;
        if(!head || !head->next)
            return head;
        ListNode* slow=head, *fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        return merge(sortList(head),sortList(fast));
        
    }
};