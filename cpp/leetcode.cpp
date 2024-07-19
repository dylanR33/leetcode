#include "leetcode.hpp"

int Solution::removeElementSolOne(std::vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;
    // Number of values equal to val.
    int val_count{};
    // Number of values not equal to val.
    int k{};
    std::vector<int>::iterator front_it = nums.begin();
    std::vector<int>::iterator end_it = nums.end() - 1;
    int temp{};

    while (front_it <= end_it) {
        // End iterator is equal to the value.
        if (*end_it == val) { 
            // Zero out the match.
            *end_it = 0;
            end_it--;
            val_count++;
        // Front iterator is equal to the value.
        } else if (*front_it == val) { 
            // Swap
            temp = *front_it;
            *front_it = *end_it;
            *end_it = temp;
            
            // Zero the match out.
            *end_it = 0;
            
            val_count++;
            front_it++;
            end_it--;
            // Neither is equal to value, continue iterating without moving end iterator.
        } else { 
            front_it++;
        }
    }
    // Subtract the number of occurrences of val from the total number of elements
    // to get k (the number of non val elements).
    k = nums.size() - val_count;
    return k;
}

int Solution::removeElementSolTwo(std::vector<int>& nums, int val) {
    // Number of values that do not = val. Also used as an iterator
    // across nums for swapping occurances of val with a non-val element
    // in nums. The amount of swaps = the number of values not = to val.
    int k{0};
    // Iterate through full array.
    for (int i = 0; i < nums.size(); i++) {
        // If current value != val then swap that value with
        // the value at the kth index.
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
