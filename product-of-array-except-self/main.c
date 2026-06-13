#include <stdlib.h>
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *answer = malloc(numsSize * (sizeof(int)));
    *returnSize = numsSize;
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        answer[i] = answer[i - 1] * nums[i - 1];
    }
    int right_p = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        answer[i] = answer[i] * right_p;
        right_p = right_p * nums[i];
    }
    return answer;
}
