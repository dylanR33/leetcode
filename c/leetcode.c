#include "leetcode.h"

int isSubsequence(char* s, char* t) {
    char* s_ptr = s;
    char* t_ptr = t;

    while (*s_ptr) {
        // We reached the end of t before s: not a subsequence.
        if (!*t_ptr && *s_ptr) {
            return 0;
        // The char is s matches char in t, so advance.
        } else if (*s_ptr == *t_ptr) {
            s_ptr++;
            t_ptr++;
        // No match, continue across t searching for a match.
        } else {
            t_ptr++;
        }
    }
    return 1;
}


void rotate_linear_space_helper(int* nums, int numsSize, int left_element, 
                                int right_element) {
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
    rotate_linear_space_helper(nums, numsSize, left_element, right_element);

    // Reverse up to the k - 1 element
    left_element = 0;
    right_element = k - 1;
    rotate_linear_space_helper(nums, numsSize, left_element, right_element);

    // Reverse the remaining portion (from the kth element to the size-1 element)
    left_element = k;
    right_element = numsSize - 1;
    rotate_linear_space_helper(nums, numsSize, left_element, right_element);
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

