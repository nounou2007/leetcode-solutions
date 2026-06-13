
void rotate(int *nums, int numsSize, int k)
{
    k = k % numsSize;

    while (k > 0)
    {
        int temp = nums[numsSize - 1];
        for (int j = numsSize - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
        k--;
    }
}
#the better version
void reverse(int *nums, int left, int right)
{

    while (left < right)
    {
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
        left++;
        right--;
    }
}

void rotate(int *nums, int numsSize, int k)
{
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}