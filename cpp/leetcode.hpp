#ifndef LEETCODE_HPP
#define LEETCODE_HPP

#include<vector>

class Solution {
    public:
        // Remove all occurances of 'val' from the passed in vector.
        //
        // @param nums : vector to remove desired val from.
        //
        // @param val : value to remove from nums.
        //
        // return : the number of values in nums not equal to val.
        int removeElementSolOne(std::vector<int>& nums, int val);
        int removeElementSolTwo(std::vector<int>& nums, int val);

    private:

};

#endif
