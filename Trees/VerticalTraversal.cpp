/* Vertical Traversal of a binary Tree */

class Solution {
public:
    map<pair<int,int>,vector<int>>m;
    void util(Node* root, int h, int l)
    {
        if(!root)
            return;
        m[{h,l}].push_back(root->data);
        util(root->left,h-1,l+1);
        util(root->right,h+1,l+1);
        
    }
    vector<int> verticalOrder(Node *root)
    {
        vector<int>sol;
        util(root,0,0);
        for(auto it:m)
        {
            int n = it.second.size();
            for(int i = 0;i<n;i++)
                sol.push_back(it.second[i]);
        }
        return sol;
    }
};