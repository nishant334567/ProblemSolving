/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* p = head;
        vector<int>v;
        while(p)
        {
            v.push_back(p->val);
            p=p->next;
        }
        int n = v.size();
        int i=0,ans=0;
        while(i<n)
        {
            ans = ans+v[n-i-1]*pow(2,i);
            i++;
        }
        return ans;
    }
};