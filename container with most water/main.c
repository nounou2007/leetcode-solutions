int min(int a, int b)
{
    return (a < b) ? a : b;
}
int maxArea(int *height, int heightSize)
{
    int i = 0;
    int j = heightSize - 1;
    int max = 0;
    while (i < j)
    {
        if (min(height[i], height[j]) * (j - i) > max)
        {
            max = min(height[i], height[j]) * (j - i);
        }
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return max;
}
