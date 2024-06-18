#include "leetcode.h"

void rotate_linear_space_helper(int* nums, int numsSize, int k, 
                                int left_element, int right_element) {
    int temp = 0;
    // Reverse the elements of an array.
    while (left_element < right_element) {
        temp = nums[left_element];
        nums[left_element] = nums[right_element];
        nums[right_element] = temp;
        left_element++;
        right_element--;
    }
}

void rotate_linear_space(int* nums, int numsSize, int k) {
    // Ensure that k is within the range of the array. If it is 
    // greater than or equal to the size of the array then the remainder 
    // allows us to wrap back around the indices.
    k %= numsSize;

    // Reverse the full array.
    int left_element = 0;
    int right_element = numsSize - 1;
    rotate_linear_space_helper(nums, numsSize, k, left_element, right_element);

    // Reverse up to the k - 1 element
    left_element = 0;
    right_element = k - 1;
    rotate_linear_space_helper(nums, numsSize, k, left_element, right_element);

    // Reverse the remaining portion (from the kth element to the size-1 element)
    left_element = k;
    right_element = numsSize - 1;
    rotate_linear_space_helper(nums, numsSize, k, left_element, right_element);
}

void rotate_o_of_n_space(int* nums, int numsSize, int k) {
    // Create a new array the same size as the one being passed in.
    int temp_arr[numsSize];
    
    // Assign the i + k element of temp_arr to the ith element of the
    // original array. We use the remainder of (i + k)/size to wrap back 
    // around the indices when i + k is greater than or equal to the 
    // size of the array.
    for (int i = 0; i < numsSize; i++) {
        temp_arr[(i + k) % numsSize] = nums[i];
    }

    // Copy the values of the temporary array to the original.
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp_arr[i];
    }
}

