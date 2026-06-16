# 33. Search in Rotated Sorted Array

**Difficulty:** Medium
**Pattern:** Binary Search (modified)
**Link:** https://leetcode.com/problems/search-in-rotated-sorted-array/

---

## Problem

A sorted array has been rotated at some unknown pivot. Search for a target and return its index, or `-1` if not found. Must run in **O(log n)**.

```
Input:  nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input:  nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input:  nums = [1], target = 0
Output: -1
```

---

## Intuition

Even though the array is rotated, **one half is always sorted**. Identify which half is sorted, then check if the target falls in that half. If yes, search there. If no, search the other half.

---

## Solution

```python
def search(nums, target):
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return mid

        # left half is sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1   # target is in left half
            else:
                left = mid + 1    # target is in right half
        # right half is sorted
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1    # target is in right half
            else:
                right = mid - 1   # target is in left half

    return -1
```

**Time:** O(log n)
**Space:** O(1)

---

## Walkthrough

```
nums = [4, 5, 6, 7, 0, 1, 2], target = 0

left=0, right=6, mid=3 → nums[3]=7
Left half [4,5,6,7] is sorted. Is 0 in [4,7)? No → search right: left=4

left=4, right=6, mid=5 → nums[5]=1
Right half [1,2] is sorted. Is 0 in (1,2]? No → search left: right=4

left=4, right=4, mid=4 → nums[4]=0 == target ✓ → return 4
```

---

## The key condition: `nums[left] <= nums[mid]`

This tells us the left half has no rotation point (it's cleanly sorted). The `<=` handles the case where `left == mid` (single element).

---

## Common mistakes

- Using strict `<` instead of `<=` when comparing `nums[left]` to `nums[mid]`
- Forgetting the equal sign in `nums[left] <= target < nums[mid]`

---

## Related problems

- [153. Find Minimum in Rotated Sorted Array](153-find-minimum-in-rotated-sorted-array.md)
- [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) — with duplicates (O(log n) best, O(n) worst)