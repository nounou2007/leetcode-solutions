int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = malloc(2 * sizeof(int)); // allocate space for 2 integers
    for (int i = 0; i < numsSize; i++)     // runs n times
    {
        for (int j = i + 1; j < numsSize; j++) // runs n*(n-1)/2 times
        {
            if (nums[i] + nums[j] == target) // check if pair sums to target
            {
                result[0] = i;   // store first index
                result[1] = j;   // store second index
                *returnSize = 2; // tell leetcode we return 2 elements
                return result;   // exit immediately
            }
        }
    }
    return NULL; // no solution found (won't happen per problem rules)
}
// time complexity = O(n²)
// space complexity = O(1)