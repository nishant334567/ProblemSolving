class Solution {
public:
    bool search(vector<int>&v,int target)
    {
        int start = 0;
        int end = v.size()-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(v[mid]==target)
                return true;
            if(v[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0;i<row;i++)
        {
            if(search(matrix[i],target))
                return true;
            
        }
        return false;
    }
};