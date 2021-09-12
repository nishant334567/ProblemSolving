/* Leetcode medium leet154 follow up problem*/

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        while(start<end)
        {
            int mid = (start+end)/2;
            if(arr[mid]<arr[end])
                end = mid;
            else
                start = mid+1;
        }
        return arr[start];
    }
};