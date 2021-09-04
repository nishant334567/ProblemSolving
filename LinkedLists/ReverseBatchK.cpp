class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head || !head->next)
            return head;
        struct node* curr, *next,*prev;
        prev=NULL;
        curr=head;
        next=curr->next;
        int i=0;
        while(curr!=NULL &&i<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        if(next)
            head->next=reverse(next,k);
        return prev;
    }
}