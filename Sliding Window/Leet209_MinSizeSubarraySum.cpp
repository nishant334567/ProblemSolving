/* ------------------------------------209. Minimum Size Subarray Sum ---------------------------------------------------*/
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

/* start taking in consideration,the sum of all subarrays starting at l(initially 0) and ending with r
if(for any l,r ) if(sum is >=target), start taking these length subarray into ans, moving left till sum is less than target
 */
 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sum=0;
        int ans = INT_MAX;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
         
        }
        return ans==INT_MAX?0:ans;
    }
};