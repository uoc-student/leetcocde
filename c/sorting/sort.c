#include <stdio.h>
#include <assert.h>

void swap(int *index1, int *index2);
void print_arr(int *arr, int size);
void bubble_sort(int *arr, int size);
void check_result(int *arr, int *sol, int size);


void main() {
    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sol1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size_arr1 = 10;
    int arr2[] = {0, 1, 2, 3, 4};
    int size_arr2 = 5;
    int arr3[] = {-9, 100, 4, -300, 75, 0,-50};
    int sol3[] = {-300, -50, -9, 0, 4, 75, 100};
    int size_arr3 = 7;
    int arr4[] = {-9, -10};
    int sol4[] = {-10, -9};
    int size_arr4 = 2;
    int arr5[] = {2, 1};
    int sol5[] = {1, 2};
    int size_arr5 = 2;

    // arr1
    bubble_sort(arr1, size_arr1);
    check_result(arr1, sol1, size_arr1);
    // arr2
    bubble_sort(arr2, size_arr2);
    check_result(arr2, arr2, size_arr2);
    // arr3
    bubble_sort(arr3, size_arr3);
    check_result(arr3, sol3, size_arr3);
    // arr4
    bubble_sort(arr4, size_arr4);
    check_result(arr4, sol4, size_arr4);
    // arr5
    bubble_sort(arr5, size_arr5);
    check_result(arr5, sol5, size_arr5);
}


/*
 * swap -> swaps in place two elements of an array.
 * params: two pointers to the positions to be swaped.
 */
void swap(int *index1, int *index2) {
    assert(index1 != NULL && index2 != NULL);

    int tmp = *index1;
    *index1 = *index2;
    *index2 = tmp;
}


/*
 * print_arr -> prints the array positions and its elements.
 * params: pointer to integer array, size of the array.
 */
void print_arr(int *arr, int size) {
    assert(arr != NULL);

    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}


/*
 * check_result -> compares the array against the expected array.
 * params: pointer to array, pointer to expected array, size of the array.
 */
void check_result(int *arr, int *sol, int size) {
    assert(arr != NULL && sol != NULL);

    for (int i = 0; i < size; i++) {
        if (arr[i] != sol[i]) {
            printf("ERROR: Comparison failed at index %d\n", i);
            printf("expected  %d and got %d\n", sol[i], arr[i]);
            return;
        }
    }

    printf("OK !!\n");
}


/*
 * bubble_sort -> sorts the array in place in ascencing order in time O(n^2).
 * params: pointer to array, size of the array.
 */
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}


/*
 *
 */
void merge_sort(int *arr, int size) {
}
