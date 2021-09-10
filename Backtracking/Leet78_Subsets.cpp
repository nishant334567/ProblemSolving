class Solution {
public:
    void util(vector<vector<int>>&sol,vector<int>&temp,int start,vector<int>&nums)
    {
        if(start==nums.size())
        {
            sol.push_back(temp);
            return;
        }
        
        temp.push_back(nums[start]);
        util(sol,temp,start+1,nums);
        temp.pop_back();
        util(sol,temp,start+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>sol;
        vector<int>temp;
        util(sol,temp,0,nums);
        return sol;
    }
};