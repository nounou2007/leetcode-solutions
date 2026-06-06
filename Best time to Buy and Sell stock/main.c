int maxProfit(int *prices, int pricesSize)
{
    int diff = 0;

    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            if (prices[j] - prices[i] > diff)
            {
                diff = prices[j] - prices[i];
            }
        }
    }
    return diff;
}
#the better version
int maxProfit(int *prices, int pricesSize)
{
    int minprice = prices[0];
    int maxprofit = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (minprice > prices[i])
        {
            minprice = prices[i];
        }
        if (prices[i] - minprice > maxprofit)
        {
            maxprofit = prices[i] - minprice;
        }
    }
    return maxprofit;
}