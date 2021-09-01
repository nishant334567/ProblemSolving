/* 103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
 (i.e., from left to right, then right to left for the next level and alternate between). */

 /* Solution 
    Using queue do normal level order traversal, with flag for every level, switching 
    fill array for a level from start to end (flag==0) && end to start(flag==1)
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> sol;
        queue<TreeNode*>q;
        q.push(root);
        int flag=1;
        while(!q.empty())
        {
            int l = q.size();
            vector<int>temp(l);
            int i = 0;
            while(l--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(flag==1)
                {
                    temp[i++]=curr->val;
                }
                else{
                    temp[l] = curr->val;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
            flag=1-flag;
            sol.push_back(temp);
        }
        return sol;
    }
};