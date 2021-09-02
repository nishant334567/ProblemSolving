/* ------------------------------------------------ 1004. Max Consecutive Ones III ------------------------------------
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can
 flip at most k 0's.
 */

/* We have two pointers l and r
we can move r without until we have ( 0's count < k ), updating maxLength since all these subarrays have safe 0 count in them
now at this point we have (zero's > k), we cant move r since we have already exhausted 0
now r will only move when again 0's count is under control, for that we have to move l (i.e l++), so that when l encounters 0,
it will drop it and 0 count decreses, till the point it's equal to k

*/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l=0, r=0,zeroC=0;
        int maxLen=INT_MIN;
        for(r=0;r<A.size();r++)
        {
            if(A[r]==0)
                zeroC++;
            while(zeroC>K)
            {
                if(A[l]==0)
                    zeroC--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};