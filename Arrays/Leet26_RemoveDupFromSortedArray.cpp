/* approach 1, using hashset
tc: O(nlogn)+o(n)
sc: o(n) 

approach 2: two pointer
only valid for sorted array
tc: o(n)
sc: o(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>s;
        // s.insert(nums.begin(),nums.end());
        // int i=0;
        // for(auto n:s)
        //     nums[i++]=n;
        // return s.size();
        int i=0,j=1,n=nums.size();
        while(j<n)
        {
            if(nums[i]==nums[j])
                j++;
            else
                nums[++i]=nums[j++];
        }
        return n==0?0:i+1;
    }
};