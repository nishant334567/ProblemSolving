/* approach 1  */
/* for every element in list 2 traverse whole elements of list 1
TC: O(m*n)
SC: O(1) */

/* approach 2 */
/* hash table, hash all elements of list 1
then traverse list 2, check if its their( hast node i.e address, not the value)
TC: O(n+m)
SC: O(n) */

/* approach 3 optimal approach
traverse simul. both list, if any say p1->next hits null, change it to p2 and vice verse 
if both hits NULLi.e p1->next and p2->next hits NULL return NULL, since no common node
if(common element is their return any of p1 && p2)
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode *p1 = a, *p2=b;
        while(p1!=p2)
        {
            if(!p1->next && !p2->next)
                return NULL;
            if(!p1->next)
                p1=b;
            else
                p1=p1->next;
            if(!p2->next)
                p2=a;
            else
                p2=p2->next;
        }
        if(!p1 && !p2) return NULL;
        return p1;
    }
};
