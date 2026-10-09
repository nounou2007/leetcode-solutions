int findBound(int *nums, int n, int target, int findLeft)
{
    int s = 0, e = n - 1, ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            if (findLeft)
                e = mid - 1;
            else
                s = mid + 1;
        }
    }
    return ans;
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = malloc(2 * sizeof(int));
    result[0] = findBound(nums, numsSize, target, 1);
    result[1] = findBound(nums, numsSize, target, 0);
    *returnSize = 2;
    return result;
}
// O(log n) the time complexity
//we used binary search as an approach