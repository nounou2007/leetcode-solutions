#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int longestConsecutive(int *nums, int numsSize)
{
    int count = 1;
    int max_count = 1;
    int i = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    if (numsSize == 0)
        return 0;
    while (i < numsSize - 1)
    {
        if (nums[i] + 1 == nums[i + 1])
        {
            count++;
            i++;
        }
        else if (nums[i] == nums[i + 1])
        {
            i++;
        }
        else
        {
            if (max_count < count)
            {
                max_count = count;
            }
            count = 1;
            i++;
        }
    }
    if (max_count < count)
    {
        max_count = count;
    }
    return max_count;
}