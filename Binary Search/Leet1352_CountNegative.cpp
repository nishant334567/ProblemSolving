/* ---------------------------------- 1351. Count Negative Numbers in a Sorted Matrix-----------------------------------*/
/*
Given a sorted row-wise and column-wise 2D- matrix, find the number of negative values in int

4   3   2   -1
3   2   1   -1
1   1  -1   -2
-1 -1  -2   -3

o/p ---> 8 (There are 8 negatives number in the matrix.)
*/

/* 3 approaches 

Approach 1: O(m*n) - Visit all the cells and count negative
    
Approach 2: O(mlogn) - Apply binary search on every row
    for binary search, find mid
    case1: 
        if(mid<0) every following values in the row will also be negative, since given the matrix is sorted row wise as well
        count them and then, high = mid-1 (now the search has to be done only on left of it)
    case2:
    if(mid>0)
        that means all values on left of it is also positive, the the search array is the right of mid
        i.e low=mid+1;
   */
  int binarySearch(vector<int>&v)
    {
        int count = 0;
        int l=0, r=v.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(v[mid]<0)
            {
                count+=r-mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return count;
    }

/*
Approach 3: O(m+n) 
start from top right and move towards left bottom, how?
case1: grid[i][j] < 0
    all the values below it is negative,count and now we just have to count in array[i][j-1] sized array
else (i.e if grid[i][j]>0)
    then the search array is array[i+1][j] (because all the values on left of the array is +ve)
*/

int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count=0;
        
        int j = col-1;
        int i = 0;
        while(j>=0 && i<row)
        {
            if(grid[i][j]<0)
            {
                count+=row-i;
                j--;
            }
            else{
                i++;
            }
        }
        return count;
    }