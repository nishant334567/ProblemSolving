/* https://leetcode.com/problems/array-partition-i/   561. Array Partition I

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum. 
Input: nums = [1,4,3,2]
Output: 4*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0,i=0,j=nums.size()-1;
        while(i<j){
            ans+=min(nums[i],nums[i+1]);
            i+=2;
        }
        return ans;
    }
};