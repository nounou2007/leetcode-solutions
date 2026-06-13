void sortColors(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; i < numsSize - 1; j++)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}