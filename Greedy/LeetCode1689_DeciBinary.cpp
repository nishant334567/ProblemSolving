/* --------------------  1689. Partitioning Into Minimum Number Of Deci-Binary Numbers -------------------------------------------*/

/* A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary
numbers needed so that they sum up to n. 

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32    */

class Solution {
public:
    /*
        if we are able to form max_digit we'll be able to 
        for all the remaining digits of n
        About max_element :
        --> Return an iterator to the max element in the given range
        --> Return an iterator to the 1st max element if multiple max present
    */
    int minPartitions(string n) {
          return *max_element(n.begin(),n.end())-'0';
    }
};