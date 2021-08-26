/* 198. House Robber LEETCODE
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:

Input: nums = [1,2,3,1]
Output: 4
 */

/* Explanation
At every house robber has an option to rob it or leave it
let dp[i] is the amount 
dp[i] = max(dp[i-1], a[i]+dp[i-2])

dp[i-1] when you dont rob that house
dp[i-2] when you rob, therefore you have to leave dp[i-1] and look for the dp[i-2]
for maximum from them adding a[i] to it (since you robbed it)
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        
        if(nums.size()==1)
            return dp[0];
        dp[1]=max(nums[0],nums[1]);
        if(nums.size()==2)
            return dp[1];
        for(int i = 2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};