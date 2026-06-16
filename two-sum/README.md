# 1. Two Sum

**Difficulty:** Easy
**Pattern:** Hash Map
**Link:** https://leetcode.com/problems/two-sum/

---

## Problem

Given an array `nums` and a target, return the **indices** of the two numbers that add up to the target. Each input has exactly one solution.

```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]   (nums[0] + nums[1] = 2 + 7 = 9)

Input:  nums = [3, 2, 4], target = 6
Output: [1, 2]
```

---

## Solution

```python
def two_sum(nums, target):
    seen = {}   # value → index

    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
```

**Time:** O(n)
**Space:** O(n)

---

## Intuition

For each number, we need `target - num`. Instead of searching the array (O(n) per lookup), store numbers in a hash map for O(1) lookup.

One pass: check if the complement exists, then add the current number. Order matters — add *after* checking to avoid using the same element twice.

---

## Why not Two Pointers here?

Two pointers require a **sorted** array and return **values**, not **indices**. Sorting destroys original indices. Use hash map when you need index tracking.

| Problem | Sorted? | Need indices? | Use |
|---|---|---|---|
| Two Sum (#1) | No | Yes | Hash Map |
| Two Sum II (#167) | Yes | No (1-indexed ok) | Two Pointers |

---

## Common mistakes

- Checking `seen` after adding `num` — misses valid pairs (and could match an element with itself)
- Returning values instead of indices — read the problem carefully

---

## Related problems

- [167. Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) — sorted input, two pointers
- [15. 3Sum](https://leetcode.com/problems/3sum/) — sort + two pointers extension