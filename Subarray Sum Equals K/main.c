int subarraySum(int *nums, int numsSize, int k)
{
    int s = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int sum = 0;
        for (int j = i; j < numsSize; j++)
        {
            sum = sum + nums[j];
            if (sum == k)
            {
                s++;
            }
        }
    }
    return s;
}
#there is a better version using hash maps