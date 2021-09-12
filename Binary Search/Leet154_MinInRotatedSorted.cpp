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
                return arr[mid];
            if(arr[mid]<arr[end])
                end=mid;
            else if(arr[mid]>arr[end])
                start = mid+1;
            else
                end = end-1;
        }
        return arr[start];
    }
};