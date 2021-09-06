/* -----------------------------------------------------113. Path Sum II -----------------------------------------------*/
/* Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references. */

class Solution {
public:
    void util(vector<vector<int>>&ans,vector<int>&sol,TreeNode* root, int sum, int tSum)
    {
        if(sum==tSum && (!root->left && !root->right))
        {
            sol.push_back(root->val);
            // since we have considered the sum, but havent pushed it yet
            ans.push_back(sol);
            sol.pop_back();
            return;
        }
        if(!root) //sum>tSum shouldnt be used, since negative sum also possible
            return;
        sol.push_back(root->val);
        if(root->left) util(ans,sol,root->left,sum+root->left->val,tSum);
        // sol.pop_back();
        if(root->right) util(ans,sol,root->right,sum+root->right->val,tSum);
        sol.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        
        vector<vector<int>>ans;
        vector<int>sol;
        util(ans,sol,root,0+root->val,targetSum);
        return ans;
    }
};