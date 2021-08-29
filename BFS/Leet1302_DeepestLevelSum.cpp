
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


/* Recursive Approach */

class Solution {
public:
    int sum=0,max_l=INT_MIN;
    void level_(TreeNode* root, int level)
    {
        if(!root)
            return;
        if(max_l<level){
            sum=root->val;
            max_l=level;
        }
        else if(max_l==level){
            sum+=root->val;
            // return;
        }
        level_(root->left,level+1);
        level_(root->right,level+1);
    }

    int deepestLeavesSum(TreeNode* root) {
    level_(root,0);
        return sum;
    }