/* 213. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 */

/* Explanation

ROB 1 VARIATION
----------------

you cant rob 1st and last simul
so if you pick 1st then you dont have to conside the last, rob in given array of houses from (0,n-1)
or if you decide to pik last then you have to leave 1st , rob in given array of houses from (1,n-2)
*/
class Solution {
public:
    int rob(int l,int r,vector<int>&nums)
    {
        vector<int>dp(r-l+1);
        dp[0]=nums[l];
        if(r-l+1==1)
            return dp[0];
        dp[1]=max(nums[l],nums[l+1]);
        if(r-l+1==2)
            return dp[1];
        for(int i = l+2;i<=r;i++)
        {
            dp[i-l]=max(dp[i-l-1],nums[i]+dp[i-l-2]);
        }
        return dp[dp.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size()?nums[0]:0;
        return max(rob(0,nums.size()-2,nums),rob(1,nums.size()-1,nums));
    }
};