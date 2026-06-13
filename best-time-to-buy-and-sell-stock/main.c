int maxProfit(int *prices, int pricesSize)
{
    int diff = 0;                                    // tracks max profit found
    for (int i = 0; i < pricesSize; i++)             // runs n times (buy day)
    {
        for (int j = i + 1; j < pricesSize; j++)     // runs n*(n-1)/2 (sell day)
        {
            if (prices[j] - prices[i] > diff)        // if current profit is bigger
            {
                diff = prices[j] - prices[i];        // update max profit
            }
        }
    }
    return diff; // return best profit found
}
// time complexity = O(n²)
// space complexity = O(1)
#the better version
int maxProfit(int *prices, int pricesSize)
{
    int minprice = prices[0];  // track lowest price seen so far
    int maxprofit = 0;         // track best profit seen so far
    for (int i = 1; i < pricesSize; i++)              // runs n-1 times
    {
        if (minprice > prices[i])                     // found a new lowest price
            minprice = prices[i];                     // update minimum
        if (prices[i] - minprice > maxprofit)         // current profit better?
            maxprofit = prices[i] - minprice;         // update max profit
    }
    return maxprofit; // return best profit
}
// time complexity = O(n)
// space complexity = O(1)