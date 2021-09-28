/* approach 1: 
Use 3 loop ans a set 
TC: O(n^3logm) m=no of enteries in ser
SC: O(M)

approach 2
run o->n and store frequencies in hashmap
use 2 loop, lookup hashmap and set
TC: O(n^2logm)
SC: O(m)+O(n)

approach 3
sort array
run a loop and two pointer approach to solve, without using set
TC: O(n^2)
SC: O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>sol;
        // vector<int>
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(i==0 || (i>0 && arr[i]!=arr[i-1]))
            {
                // temp[0]=arr[i];
                int start = i+1, end = n-1;
                while(start<end)
                {
                    if(arr[start]+arr[end]+arr[i]==0)
                    {
                        // temp[0]=arr[start];
                        // temp[1]=arr[end];
                        sol.push_back({arr[i],arr[start],arr[end]});
                        while(start<end && arr[start]==arr[start+1]) start++;
                        while(start<end && arr[end]==arr[end-1]) end--;
                        start++;
                        end--;
                    }
                    else if(arr[start]+arr[end]+arr[i]<0)
                    {
                        start++;
                    }else end--;
                }
            }
        }
        return sol;
    }
};