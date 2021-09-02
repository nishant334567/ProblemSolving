/* ------------------------------------------ 239. Sliding Window Maximum ----------------------------------------- 

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/

/* we maintain a deque that keeps the valid index(that falls with k ) && and relavant values that are possible candidates
for ans*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++)
        {
            // for every i we check if deque has valid index 
            
            if(!dq.empty() && i-dq.front()==k)
                dq.pop_front();
            
            //and relavant values
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};