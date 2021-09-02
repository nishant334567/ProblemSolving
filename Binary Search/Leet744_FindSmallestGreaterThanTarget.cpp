/* 744. Find Smallest Letter Greater Than Target */
/* Given the array is sorted in increasing order */

/* Any sorted sequence gives a feel to apply binary search */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if(t>=letters[n-1])
            return letters[0];
        char res;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(letters[mid]<=target)
                l = mid+1;
            else{
                res = letters[mid];
                r = mid-1;
            }
        }
        return res;
    }
};