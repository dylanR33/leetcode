#include "leetcode.h"

void rotate_linear_space_helper(int* nums, int numsSize, int k, 
                                int left_element, int right_element) {
    int temp = 0;
    while (left_element < right_element) {
        temp = nums[left_element];
        nums[left_element] = nums[right_element];
        nums[right_element] = temp;
        left_element++;
        right_element--;
    }
}

void rotate_linear_space(int* nums, int numsSize, int k) {
    // Ensure that k is within the range of the array.
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

void rotate(int* nums, int numsSize, int k) {
    int* temp_arr = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp_arr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp_arr[i];
    }
    free(temp_arr);
}

