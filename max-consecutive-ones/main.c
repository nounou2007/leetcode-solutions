int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int sum = 0;
    int max_sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int temp = sum;
        if (nums[i] == 1)
        {
            sum++;
            if (sum > max_sum)
                max_sum = sum;
        }
        else
        {
            if (temp > max_sum)
            {
                max_sum = temp;
            }
            sum = 0;
        }
    }
    return max_sum;
}