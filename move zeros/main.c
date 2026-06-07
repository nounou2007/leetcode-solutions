void moveZeroes(int *nums, int numsSize)
{
    int last = 0;                      // tracks next available position for non-zero
    for (int i = 0; i < numsSize; i++) // runs n times
    {
        if (nums[i] != 0) // found a non-zero element
        {
            nums[last] = nums[i]; // place it at next available spot
            last++;               // move available spot forward
        }
    }
    for (int j = last; j < numsSize; j++) // runs remaining positions
    {
        nums[j] = 0; // fill rest with zeros
    }
}
// time complexity = O(n)
// space complexity = O(1)