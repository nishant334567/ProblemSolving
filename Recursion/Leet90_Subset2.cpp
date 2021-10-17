class Solution {
public:
    vector<vector<int>>sol;
    void util(int ind,vector<int>&ds,vector<int>&nums)
    {
        sol.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            util(i+1,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>>subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        util(0,ds,nums);
        return sol;
    }
};