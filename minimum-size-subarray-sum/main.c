int minSubArrayLen(int target, int *nums, int numsSize)
{
    int right = 0, left = 0, sum = 0;
    int min_length = INT_MAX;

    while (right < numsSize)
    {
        sum += nums[right];

        while (sum >= target)
        {
            int window_size = right - left + 1;
            if (window_size < min_length)
                min_length = window_size;
            sum -= nums[left];
            left++;
        }
        right++;
    }

    return (min_length == INT_MAX) ? 0 : min_length;
}