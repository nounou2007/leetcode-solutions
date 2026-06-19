int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    *returnSize = digitsSize;
    int right = digitsSize - 1;
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        digits[i] += 1;
        if (digits[i] < 10)
        {
            return digits;
        }

        digits[i] = 0;
    }

    int *result = malloc(sizeof(int) * (digitsSize + 1));
    *returnSize = digitsSize + 1;
    result[0] = 1;
    for (int i = 1; i < digitsSize + 1; i++)
    {
        result[i] = 0;
    }
    return result;
}