int pivotIndex(int *nums, int numsSize)
{
    int sum_left = 0;
    int total = 0;
    for (int i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        int right_sum = total - sum_left - nums[i];
        if (sum_left == right_sum)
        {
            return i;
        }
        else
        {
            sum_left += nums[i];
        }
    }
    return -1;
}