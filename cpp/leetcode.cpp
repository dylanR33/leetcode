#include "leetcode.hpp"

int Solution::removeElement(std::vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;

    int val_count{};
    int k{};
    std::vector<int>::iterator front_it = nums.begin();
    std::vector<int>::iterator end_it = nums.end() - 1;
    int temp{};

    while (front_it <= end_it) {
        if (*end_it == val) { // End iterator is equal to the value.
            end_it--;
            val_count++;
        } else if (*front_it == val) { // Front iterator is equal to the value.
            // Swap
            temp = *front_it;
            *front_it = *end_it;
            *end_it = temp;

            val_count++;
            front_it++;
            end_it--;
        } else { // Neither is equal to value, continue iterating without moving end iterator.
            front_it++;
        }
    }
    k = nums.size() - val_count;
    return k;
}
