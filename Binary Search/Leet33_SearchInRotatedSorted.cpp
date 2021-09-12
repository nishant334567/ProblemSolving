/* Extension of minimum in rotated sorted */

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mid=0;
        while(start<end)
        {
            mid = (start+end)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(arr[mid]<arr[prev] && arr[mid]<arr[next])
                return mid;
            if(arr[mid]<arr[end])
                end=mid;
            else if(arr[mid]>arr[end])
                start = mid+1;
            else
                end = end-1;
        }
        return start;
    }
    int search(int start,int end,vector<int>&nums,int target)
    {
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                end = mid-1;
            else
                start = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int min = findMin(nums);
        int end = nums.size()-1;
        cout<<"min"<<min;
        if(nums[min]==target)
            return min;
        if(nums[min]<target)
        {
            if(target>nums[end])
            {
                return search(0,min-1,nums,target);
            }
            else
            {
                return search(min+1,end,nums,target);
            }
        }
        return -1;
    }
};