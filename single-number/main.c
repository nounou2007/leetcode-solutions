#include <stdlib.h>
int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}
int singleNumber(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int i = 0;
    while (i < numsSize)
    {
        if (i == numsSize - 1 || nums[i] != nums[i + 1])
        {
            return nums[i];
        }
        i += 2;
    }
    return -1;
}