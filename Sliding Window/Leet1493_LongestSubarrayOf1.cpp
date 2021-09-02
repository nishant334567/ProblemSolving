/* --------------------------1493. Longest Subarray of 1's After Deleting One Element------------------------------------*/
/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.
*/

/* Extension of LEETCODE 1493
for a subarray find largest consecutive 1 dropping 1 elementt */

int longestSubarray(vector<int>& nums) {
        int k = 1,l=0,r=0,zc=0;
        int maxLen = INT_MIN;
        for(r =0;r<nums.size();r++)
        {
            if(nums[r]==0)
                zc++;
            while(zc>k)
            {
                if(nums[l]==0)
                    zc--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen-1;
    }
