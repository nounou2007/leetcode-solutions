#include <stdlib.h>
int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}
int thirdMax(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int distinct = 1;
    int i = numsSize - 1;

    while (i > 0)
    {
        if (nums[i - 1] != nums[i])
        {
            distinct++;
        }
        if (distinct == 3)
        {
            return nums[i - 1];
        }
        i--;
    }
    return nums[numsSize - 1];
}
