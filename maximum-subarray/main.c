int maxSubArray(int *nums, int numsSize)
{
    int current_sum = nums[0];         // current subarray sum
    int max_sum = nums[0];             // best sum seen so far
    for (int i = 1; i < numsSize; i++) // runs n-1 times
    {
        if (nums[i] > current_sum + nums[i]) // fresh start better?
            current_sum = nums[i];           // start new subarray
        else
            current_sum = current_sum + nums[i]; // extend current subarray
        if (current_sum > max_sum)               // found better sum?
            max_sum = current_sum;               // update best
    }
    return max_sum; // return largest subarray sum
}
// time complexity = O(n)
// space complexity = O(1)