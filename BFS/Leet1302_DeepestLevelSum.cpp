
/* --------------------------------------    1302. Deepest Leaves Sum    ------------------------------------------------

Given the root of a binary tree, return the sum of values of its deepest leaves. */

/*Level Order Traversal */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        int sum;
        // vector<int>sol;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            sum=0;
            while(size--)
            {
                // int sum=0;
                TreeNode* temp = q.front();
                sum+=temp->val;
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }
            // sol.push_back(sum);
        }
        return sum;
    }
};