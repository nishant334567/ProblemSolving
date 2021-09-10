class Solution {
public:
    vector<int>sol(vector<int>&v1,vector<int>&v2){
        vector<int>ans;
        int l = 0,r = 0;
        while(l<v1.size() && r<v2.size())
        {
            if(v1[l]<v2[r])
            {
                ans.push_back(v1[l]);
                l++;
            }
            else
            {
                ans.push_back(v2[r]);
                r++;
            }
        }
        if(r==v2.size())
        {
            while(l<v1.size())
            {
                ans.push_back(v1[l]);
                l++;
            }
        }
        
        if(l==v1.size())
        {
            while(r<v2.size()){
            ans.push_back(v2[r]);
                r++;
            }
        }
        return ans;
    }
    void inorder(TreeNode* root1,vector<int>&v1)
    {
        if(!root1) return;
        inorder(root1->left,v1);
        v1.push_back(root1->val);
        inorder(root1->right,v1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        return sol(v1,v2);
    }
};