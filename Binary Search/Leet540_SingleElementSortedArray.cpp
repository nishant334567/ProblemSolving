/* 540. Single Element in a Sorted Array*/

/* You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
 Find this single element that appears only once. */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r=n-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                    l=mid+2;
                else
                    r=mid;
            }
            else{
                if(nums[mid]==nums[mid-1])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return nums[l];
    }
};