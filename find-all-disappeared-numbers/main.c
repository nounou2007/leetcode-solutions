#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int *result = malloc(sizeof(int) * numsSize);
    int i = 0, j = 1, count = 0;

   while (j <= numsSize) {
    if (i < numsSize && nums[i] == j) {
        i++;
        j++;
    } else if (i < numsSize && nums[i] > j) {
        result[count++] = j++;
    } else if (i < numsSize && nums[i] == nums[i-1]) {
        i++;
    } else {
        result[count++] = j++;
    }
}
    *returnSize = count;
    return result;
}