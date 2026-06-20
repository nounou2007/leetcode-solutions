#include <stdlib.h>
int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}
bool checkIfExist(int *arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), compare);

    for (int i = 0; i < arrSize; i++)
    {
        int left = 0;
        int right = arrSize - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[i] * 2 < arr[mid])
            {
                right = mid;
            }
            else if (arr[i] * 2 > arr[mid])
            {
                left = mid + 1;
            }
            else if (mid != i)
            {
                return true;
            }
            else if (arr[i] * 2 == arr[i] && mid == i)
            {
                right = mid - 1;
            }
        }
    }
    return false;
}