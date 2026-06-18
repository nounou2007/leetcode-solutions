int longestSubarray(int *nums, int numsSize)
{
    int z_count = 0;
    int left = 0;
    int max = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            z_count++;
        }
        if (z_count > 1)
        {
            if (nums[left] == 0)
                z_count--;
            left++;
        }

        if (i - left > max)
            max = i - left;
    }
    return max;
}
