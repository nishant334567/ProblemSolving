/* https://leetcode.com/problems/arranging-coins/discuss/1464585/C%2B%2B-1-liner-O(1)-solution-with-explanation */
class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(2)*sqrt(1/8.0+n)-0.5);
    }
};