/*LeetCode1425 Constrained Subsequence Sum ---------------------*/


/*-------------------amazing question ---- deque used ----- dp used ------ sliding window ----- */


/*
Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // int n = nums.size();
        // int ans = INT_MIN;
        // vector<int>dp(n);
        // for(int i = 0; i<n;i++)
        // {
        //     int max_ = 0;
        //     for(int j = max(0,i-k);j<i;j++)
        //         max_ = max(max_,dp[j]);
        //     dp[i]=max_+nums[i];
        //     ans = max(dp[i],ans);
        // }
        // return ans;
        deque<int>dq;
        int ans = INT_MIN;
        int n = nums.size();
        vector<int>dp(n); 
        for(int i = 0; i<n;i++)
        {
            int max_ = max(0,dq.empty()?0:dp[dq.front()]);
            dp[i]=max_+nums[i];
            if(!dq.empty() && i-dq.front()==k)
                dq.pop_front();
            while(!dq.empty() && dp[dq.back()]<=dp[i])
                dq.pop_back();
            dq.push_back(i);
            ans = max(dp[i],ans);
        }
        return ans;
    }
};