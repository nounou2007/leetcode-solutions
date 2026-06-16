# 53. Maximum Subarray

**Difficulty:** Medium
**Pattern:** Kadane's Algorithm
**Link:** https://leetcode.com/problems/maximum-subarray/

---

## Problem

Find the contiguous subarray with the largest sum and return its sum.

```
Input:  nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6   (subarray [4, -1, 2, 1])

Input:  nums = [1]
Output: 1

Input:  nums = [5, 4, -1, 7, 8]
Output: 23
```

---

## Intuition — Kadane's Algorithm

At each position ask: *"is it better to extend the current subarray, or start fresh from here?"*

If the running sum becomes negative, it's always better to discard it — a negative prefix only drags down any future subarray.

---

## Solution

```python
def max_sub_array(nums):
    current_sum = nums[0]
    max_sum = nums[0]

    for num in nums[1:]:
        current_sum = max(num, current_sum + num)  # extend or restart
        max_sum = max(max_sum, current_sum)

    return max_sum
```

**Time:** O(n)
**Space:** O(1)

---

## Walkthrough

```
nums =       [-2,  1, -3,  4, -1,  2,  1, -5,  4]
current_sum = -2   1  -2   4   3   5   6   1   5
max_sum =     -2   1   1   4   4   5   6   6   6
```

---

## Common mistake

Starting `current_sum = 0` — this breaks on all-negative arrays (you'd return 0 instead of the least negative element). Always initialize with `nums[0]`.

---

## Related problems

- [152. Maximum Product Subarray](152-maximum-product-subarray.md) — same concept but with multiplication and sign tracking
- [121. Best Time to Buy and Sell Stock](121-best-time-to-buy-and-sell-stock.md) — Kadane's applied to price differences