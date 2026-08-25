int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int left = 0;    
    int right = numsSize - 1; 
    int writeIndex = numsSize - 1;
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        if (leftSquare > rightSquare) {
            result[writeIndex] = leftSquare;
            left++;  
        } else {
            result[writeIndex] = rightSquare;
            right--;
        }
        writeIndex--;
    }
    *returnSize = numsSize;
    return result;
}
