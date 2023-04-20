// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

/* 
Runtime: 11 ms
Memory Usage: 7.5 MB
*/
int removeDuplicates(int* nums, int numsSize){
    int* current = nums;
    int* next = nums++;
    int k = 1; // size of resulting array;
  
    for (int i = 0; i < numsSize; i++) {
        if (*next != *current) {
            current++;
            *current = *next;
            k++;
        }
        next++;
    }

    return k;
}

/*
Status: Accepted
Runtime: 15 ms
Memory Usage: 7.4 MB

int removeDuplicates(int* nums, int numsSize){
    int* current = nums;
    int* next = nums + 1;
    int k = 1; // size of resulting array;

    while (next < nums + numsSize) {
        if (*next != *current) {
            current++;
            *current = *next;
            k++;
        }
        next++;
    }

    return k;
}
*/

void testNums(int *nums, int mumsSize, int *expectedNums, int expectedSize) {
    int k = removeDuplicates(nums, mumsSize);

    assert (k == expectedSize);
    
    for (int i = 0; i < k; i++) {
        printf("expectedNums[%d]: %d\n", i, expectedNums[i]);
        printf("nums[%d]: %d\n", i, nums[i]);
        assert (nums[i] == expectedNums[i]);
    }

    printf("**** SUCCESS! ****\n");
}


void main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int expectedNums[] = {0, 1, 2, 3, 4};
    int numsSize = sizeof(nums)/sizeof(int);
    int expectedSize = sizeof(expectedNums)/sizeof(int);

    testNums(nums, numsSize, expectedNums, expectedSize);


}