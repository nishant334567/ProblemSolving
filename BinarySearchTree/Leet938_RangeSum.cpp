/* -------------------------------------------------  938. Range Sum of BST ------------------------------------*/
Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].

/* Explanation 
    We know that inorder traversal of a binary search tree is sorted
    Do a inorder of the given tree an while processing the node, make a chack that the node vale fall in given range
*/
class Solution {
public:
    int sum=0;
    void inorder(TreeNode* root, int low, int high)
    {
        if(!root)
            return;
        inorder(root->left,low,high);
        if(root->val>=low && root->val<=high)
            sum+=root->val;
        inorder(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root,low,high);
        return sum;
    }
};