class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(!head->next)
            return head;
        struct Node* p=head,*q=p->next;
        head=NULL;
        while(p)
        {
            p->next=head;
            head=p;
            p=q;
            if(q) q=q->next;
        }
        return head;
    }
    