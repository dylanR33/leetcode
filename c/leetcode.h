#ifndef LEETCODE_H
#define LEETCODE_H

#include <stdio.h>
#include <stdlib.h>

void rotate_linear_space_helper(int* nums, int numsSize, int k, 
                                int left_element, int right_element);

void rotate_linear_space(int* nums, int numsSize, int k);

void rotate_o_of_n_space(int* nums, int numsSize, int k);

#endif
