#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int *result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int i = 0;
    int j = 0;
    while (i < numsSize)
    {
        int seen[numsSize] = {0};
        for (int i = 0; i < numsSize; i++)
            seen[nums[i] - 1] = 1;

        for (int i = 0; i < numsSize; i++)
            if (seen[i] == 0)
                result[j++] = i + 1;
        if (nums[i] != i + 1)
        {
            result[j] = i + 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}