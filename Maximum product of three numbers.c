#include <stdlib.h>

// Comparison function for qsort
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
 
    long long prod1 = (long long)nums[numsSize - 1] * 
                      nums[numsSize - 2] * 
                      nums[numsSize - 3];
    
    long long prod2 = (long long)nums[0] * 
                      nums[1] * 
                      nums[numsSize - 1];
    
    return (int)((prod1 > prod2) ? prod1 : prod2);
}
