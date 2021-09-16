/* https://leetcode.com/problems/sum-of-unique-elements/ 
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
Return the sum of all the unique elements of nums.

Input: nums = [1,2,3,2]
Output: 4
*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>umap;
        int sum=0;
        for(auto x:nums)
            umap[x]++;
        for(auto i:umap)
        {
            if(i.second==1)
                sum+=i.first;
        }
        return sum;
    }
};