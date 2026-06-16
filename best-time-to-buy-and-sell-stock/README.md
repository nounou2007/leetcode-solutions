# 121. Best Time to Buy and Sell Stock

**Difficulty:** Easy
**Pattern:** Greedy / Kadane's variant
**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

---

## Problem

Given an array `prices` where `prices[i]` is the price of a stock on day `i`, return the **maximum profit** you can achieve from one buy and one sell. You must buy before you sell. Return `0` if no profit is possible.

```
Input:  prices = [7, 1, 5, 3, 6, 4]
Output: 5   (buy at 1, sell at 6)

Input:  prices = [7, 6, 4, 3, 1]
Output: 0   (prices only go down, no profit possible)
```

---

## Intuition

Track the **lowest price seen so far** as you scan left to right. At each day, ask: *"if I sell today, what's my profit?"* Update the max profit whenever you find a better one.

You never need to look back — if a new minimum appears, any future sell is better paired with that new minimum.

---

## Solution

```python
def max_profit(prices):
    min_price = float('inf')
    max_profit = 0

    for price in prices:
        if price < min_price:
            min_price = price               # found a cheaper buy day
        elif price - min_price > max_profit:
            max_profit = price - min_price  # found a better profit

    return max_profit
```

**Time:** O(n) — single pass
**Space:** O(1) — only two variables

---

## Why it works

We never need to consider buying on day `i` and selling on day `j < i`. So a left-to-right scan with a running minimum captures every valid (buy, sell) pair efficiently.

---

## Common mistakes

- Forgetting to return `0` when prices only decrease
- Trying to update `min_price` and check profit in the same step — do min check first

---

## Related problems

- [122. Best Time to Buy and Sell Stock II](122-best-time-to-buy-and-sell-II.md) — unlimited transactions
- [53. Maximum Subarray](53-maximum-subarray.md) — same Kadane's idea