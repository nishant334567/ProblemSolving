/* 1373. Maximum Sum BST in Binary Tree */

/* Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST). */

/* every root has two values, left and right which is maximum sum path or left and right
    now root has to decide whether it will be alone, be with left/right or with both for ans to be maximum
    ans = max( ans ,  root->val , root->val + left + right , root->val + left , root->val + right )

    also root has to return a value to its parent( or one who has called root) about the best path possible with it.
 */
int ans = INT_MIN;
    int util(TreeNode* root)
    {
        if(!root) return 0;
        int left = util(root->left);
        int right =util(root->right);
        ans = max(ans,max(root->val+left+right,max(root->val,max(root->val+right,root->val+left))));
        return max(root->val+max(left,right),root->val);
    }
    int maxPathSum(TreeNode* root) {
        util(root);
        return ans;   
    }