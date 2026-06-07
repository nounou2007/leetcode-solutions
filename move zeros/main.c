void moveZeroes(int *nums, int numsSize)
{
    int last = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[last] = nums[i];
            last++;
        }
    }
    for (int j = last; j < numsSize; j++)
    {
        nums[j] = 0;
    }
}