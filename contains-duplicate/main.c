bool containsDuplicate(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)          // runs n times
    {
        for (int j = i + 1; j < numsSize; j++)  // runs n*(n-1)/2 times
        {
            if (nums[i] == nums[j])              // found a matching pair
                return true;                     // duplicate exists
        }
    }
    return false; // no duplicates found
}
// time complexity = O(n²)
// space complexity = O(1)
#a better version
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); // compare two integers for qsort
}

bool containsDuplicate(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare); // sort array O(n log n)
    for (int i = 0; i < numsSize - 1; i++)       // runs n-1 times
    {
        if (nums[i] == nums[i + 1])              // neighbors equal = duplicate
            return true;                          // duplicate found
    }
    return false; // no duplicates found
}
// time complexity = O(n log n) — dominated by sort
// space complexity = O(1)