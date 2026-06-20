#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int min_size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int *result = malloc(sizeof(int) * min_size);
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] == nums2[j])
        {
            result[k] = nums1[i];
            k++;
            i++;
            j++;
            *returnSize = k;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return result;
}