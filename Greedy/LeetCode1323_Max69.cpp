/* ---------------------------------- 1323. Maximum 69 Number ----------------------------------------------

Given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

-------------------------------------------------------------------------------------------------------------



/* Change the very first 6 we encounter from left to right */


class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i=0;
        while(s[i]!='6' && i!=s.size())
            i++;
        if(i!=s.size())s[i]='9';
        int x = stoi(s);
        return x;
    }
};