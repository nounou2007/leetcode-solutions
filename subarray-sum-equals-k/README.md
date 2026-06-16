# 560. Subarray Sum Equals K

**Difficulty:** Medium
**Pattern:** Prefix Sum + Hash Map
**Link:** https://leetcode.com/problems/subarray-sum-equals-k/

---

## Problem

Given an array `nums` and integer `k`, return the total number of subarrays whose sum equals `k`.

```
Input:  nums = [1, 1, 1], k = 2
Output: 2

Input:  nums = [1, 2, 3], k = 3
Output: 2   ([1,2] and [3])
```

---

## Intuition

`prefix_sum[j] - prefix_sum[i] = k` means the subarray from `i+1` to `j` sums to `k`.

Rearranged: we're looking for how many previous prefix sums equal `current_prefix - k`.

Store prefix sum frequencies in a hash map as we go.

---

## Solution

```python
from collections import defaultdict

def subarray_sum(nums, k):
    count = 0
    prefix_sum = 0
    freq = defaultdict(int)
    freq[0] = 1   # empty subarray has prefix sum 0

    for num in nums:
        prefix_sum += num
        count += freq[prefix_sum - k]  # how many past sums make a valid subarray
        freq[prefix_sum] += 1

    return count
```

**Time:** O(n)
**Space:** O(n)

---

## Walkthrough

```
nums = [1, 1, 1], k = 2

prefix_sum=0: freq={0:1}
num=1: prefix_sum=1, looking for 1-2=-1 → 0 found. freq={0:1,1:1}
num=1: prefix_sum=2, looking for 2-2=0  → 1 found. freq={0:1,1:1,2:1}
num=1: prefix_sum=3, looking for 3-2=1  → 1 found. freq={0:1,1:1,2:1,3:1}

count = 2 ✓
```

---

## Key insight: why `freq[0] = 1`?

This handles the case where a subarray starting at index 0 sums to `k`. Without it, `prefix_sum - k = 0` finds nothing even though the subarray is valid.

---

## Common mistakes

- Forgetting `freq[0] = 1` — fails on subarrays starting at index 0
- Trying a sliding window — doesn't work because nums can have negatives (window can't reliably shrink)

---

## Related problems

- [238. Product of Array Except Self](238-product-of-array-except-self.md) — prefix/suffix idea
- [523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) — prefix sum mod k