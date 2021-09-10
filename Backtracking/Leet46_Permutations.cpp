public:
    void util(vector<vector<int>>&sol,vector<int>&nums,int start,int end)
    {
        if(start==end)
        {
            sol.push_back(nums);
            return;
        }
        for(int i=start;i<=end;i++)
        {
            swap(nums[i],nums[start]);
            util(sol,nums,start+1,end);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>sol;
        int n = nums.size();
        util(sol,nums,0,n-1);
        return sol;
    }
};