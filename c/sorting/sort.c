#include <stdio.h>
#include <assert.h>

// main sorting algorithms
void bubble_sort(int *arr, int size);
void quick_sort(int *arr, int size);

// helper functions
void swap(int *index1, int *index2);
void print_arr(int arr[], int size);
void check_result(int arr[], int sol[], int size);
void quick_sort_recursion(int *arr, int low, int high);
int partition(int *arr, int low, int high);

void main()
{
    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sol1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {0, 1, 2, 3, 4};
    int sol2[] = {0, 1, 2, 3, 4};
    size_t size_arr2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[] = {-9, 100, 4, -300, 75, 0,-50};
    int sol3[] = {-300, -50, -9, 0, 4, 75, 100};
    size_t size_arr3 = sizeof(arr3) / sizeof(arr3[0]);
    int arr4[] = {-9, -10};
    int sol4[] = {-10, -9};
    size_t size_arr4 = sizeof(arr4) / sizeof(arr4[0]);
    int arr5[] = {2, 1};
    int sol5[] = {1, 2};
    size_t size_arr5 = sizeof(arr5) / sizeof(arr5[0]);

    //bubble_sort(arr1, size_arr1);
    //bubble_sort(arr2, size_arr2);
    //bubble_sort(arr3, size_arr3);
    //bubble_sort(arr4, size_arr4);
    //bubble_sort(arr5, size_arr5);

    quick_sort(arr1, size_arr1);
    quick_sort(arr2, size_arr2);
    quick_sort(arr3, size_arr3);
    quick_sort(arr4, size_arr4);
    quick_sort(arr5, size_arr5);

    check_result(arr1, sol1, size_arr1);
    check_result(arr2, sol2, size_arr2);
    check_result(arr3, sol3, size_arr3);
    check_result(arr4, sol4, size_arr4);
    check_result(arr5, sol5, size_arr5);
    printf("[OK] All  tests completed successfully!\n");
}


/*
 * swap -> swaps in place two elements of an array.
 * params: two pointers to the positions to be swaped.
 */
void swap(int *index1, int *index2)
{
    assert(index1 != NULL && index2 != NULL);

    int tmp = *index1;
    *index1 = *index2;
    *index2 = tmp;
}


/*
 * print_arr -> prints the array positions and its elements.
 * params: pointer to integer array, size of the array.
 */
void print_arr(int *arr, int size)
{
    assert(arr != NULL);

    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}


/*
 * check_result -> compares the array against the expected array.
 * params: pointer to array, pointer to expected array, size of the array.
 */
void check_result(int *arr, int *sol, int size)
{
    assert(arr != NULL && sol != NULL);

    for (int i = 0; i < size; i++) {
        if (arr[i] != sol[i]) {
            printf("ERROR: Comparison failed at index %d\n", i);
            printf("expected  %d and got %d\n", sol[i], arr[i]);
            return;
        }
    }
}


/*
 * bubble_sort -> sorts the array in place in ascencing order in time O(n^2).
 * params: pointer to array, size of the array.
 */
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}


/*
 * merge_sort -> sorts the array in place in ascending order in time O(n*log(n)).
 * params: pointer to array, size of array.
 */
void quick_sort(int arr[], int size)
{
    quick_sort_recursion(arr, 0, size - 1);
}


void quick_sort_recursion(int arr[], int low, int high)
{
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort_recursion(arr, low, pivot_index - 1);
        quick_sort_recursion(arr, pivot_index + 1, high);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot_value = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot_value) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}
