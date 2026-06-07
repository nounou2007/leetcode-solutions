int maxProduct(int *nums, int numsSize)
{
    int max_p = nums[0];
    int min_p = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        // save max before overwriting it
        int temp = max_p;

        // new max is biggest of 3 options
        if (nums[i] > max_p * nums[i] && nums[i] > min_p * nums[i])
            max_p = nums[i];
        else if (max_p * nums[i] > min_p * nums[i])
            max_p = max_p * nums[i];
        else
            max_p = min_p * nums[i];

        // new min is smallest of 3 options
        if (nums[i] < temp * nums[i] && nums[i] < min_p * nums[i])
            min_p = nums[i];
        else if (temp * nums[i] < min_p * nums[i])
            min_p = temp * nums[i];
        else
            min_p = min_p * nums[i];

        // update overall result
        if (max_p > result)
            result = max_p;
    }
    return result;
}
