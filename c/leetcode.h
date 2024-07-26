#ifndef LEETCODE_H
#define LEETCODE_H

#include <stdio.h>
#include <stdlib.h>

// Determine if the string s is a subsequence of the string t.
//
// @param s : subsequence string.
//
// @param t : main string.
int isSubsequence(char* s, char* t);


// Reverse array from the bounds of left_element to right_element.
//
// @param nums : array to reverse.
//
// @param numsSize : number of elements in nums.
//
// @param left_element : left bound of reversing.
//
// @param right_element : right bound of reversing.
void rotate_linear_space_helper(int* nums, int numsSize, int left_element, 
                                int right_element);


// Rotate an array by k number of steps.
//
// @param nums : array to rotate.
//
// @param numsSize : number of elements in nums.
//
// @param k : number of steps to rotate.
void rotate_linear_space(int* nums, int numsSize, int k);
void rotate_o_of_n_space(int* nums, int numsSize, int k);


#endif
