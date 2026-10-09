int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
        }
    }
    return k;
}
//instead of the sliding approach we take the good elements and put up front
//O(n) the time complexity 