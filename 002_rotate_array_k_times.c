#include <stdio.h>

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
void rotate(int* nums, int numsSize, int k);
void swap(int* nums, int index_first, int index_second);
void reverse(int *nums, int start_index, int stop_index);
void test1();
void test2();

// testing
void test1() {
    int arr_size = 7;
    int nums[] = {1,2,3,4,5,6,7};
    int expected [] = {5,6,7,1,2,3,4};
    rotate(nums, arr_size, 3);

    for (int i = 0; i < arr_size; i++) {
        if (nums[i] != expected[i]) {
            printf("ERROR: on index %d, expected %d and got %d\n", i, expected[i], nums[i]);
            return;
        }
    }
    printf("ALL GOOD!\n");
}

void test2() {
    int arr_size = 4;
    int nums[] = {-1,-100,3,99};
    int expected [] = {3,99,-1,-100};
    rotate(nums, arr_size, 2);

    for (int i = 0; i < arr_size; i++) {
        if (nums[i] != expected[i]) {
            printf("ERROR: on index %d, expected %d and got %d\n", i, expected[i], nums[i]);
            return;
        }
    }
    printf("ALL GOOD!\n");
}


void main(){
    test1();
    test2();
}

/*
* Rotating array in place, complexity O(n) + O(2*k) = O(n)
*/
void rotate(int* nums, int numsSize, int k) {
    if (!nums || numsSize < 2) {
        return;
    }

    if (k > numsSize) {
        k = k % numsSize;
    }
    
    // reverse the entire array once
    reverse(nums, 0, numsSize - 1);

    // reverse the first part (k)
    reverse(nums, 0, k - 1);

    // reverse the last part (numsSize - k)
    reverse(nums, k, numsSize - 1);
}

void swap(int* nums, int index_first, int index_second) {
    int tmp = nums[index_first];
    nums[index_first] = nums[index_second];
    nums[index_second] = tmp;
}

void reverse(int *nums, int start_index, int stop_index) {
    int tmp_start = start_index;    
    int tmp_stop = stop_index;

    while (tmp_start < tmp_stop) {
        swap(nums, tmp_start, tmp_stop);
        tmp_start++;
        tmp_stop--;
    }
}