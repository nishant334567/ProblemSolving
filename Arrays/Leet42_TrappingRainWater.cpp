/* approach 1 : for every i, find max on left, max on right
then ans+=min(left_max,right_max)-a[i]
TC: O(N^2)
SC: O(1)
approach 2 : pre calculate l[i] && r[i], i.e left and rignr max
 ans+=min(l[i],r[i])-a[i]
TC: O(N)
SC: O(2N)

optimal approach
TC: O(N)
SC: O(1)

use two pointer, left right for every decision makiing step, be it on left or right side
ensure that there is a bigger value on other side
 */


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right=n-1,res=0;
        int leftM=height[0],rightM=height[n-1];
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                leftM = max(leftM,height[left]);
                res+=leftM-height[left];
                left++;
            }
            else{
                rightM = max(rightM,height[right]);
                res+=rightM-height[right];
                right--;
            }
        }
        return res;
    }
};