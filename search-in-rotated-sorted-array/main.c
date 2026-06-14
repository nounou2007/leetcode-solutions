int search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[left] <= nums[mid]) // left half is sorted
        {
            if (target >= nums[left] && target < nums[mid])
            {
                right = mid - 1; // target in left
            }
            else
            {
                left = mid + 1; // target in right
            }
        }
        else // right half is sorted
        {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1; // target in right
            else
                right = mid - 1; // target in left
        }
    }
    return -1;
}