# 206. Reverse Linked List

**Difficulty:** Easy
**Pattern:** Iterative / Recursive pointer manipulation
**Link:** https://leetcode.com/problems/reverse-linked-list/

---

## Problem

Reverse a singly linked list.

```
Input:  1 → 2 → 3 → 4 → 5 → None
Output: 5 → 4 → 3 → 2 → 1 → None
```

---

## Solution — Iterative (preferred)

```python
def reverse_list(head):
    prev = None
    curr = head

    while curr:
        next_node = curr.next   # save next before overwriting
        curr.next = prev        # reverse the pointer
        prev = curr             # advance prev
        curr = next_node        # advance curr

    return prev   # prev is now the new head
```

**Time:** O(n)
**Space:** O(1)

---

## Walkthrough

```
Initial: None ← ? ?   1 → 2 → 3 → None
                 prev curr

Step 1:  None ← 1     2 → 3 → None
               prev  curr

Step 2:  None ← 1 ← 2    3 → None
                    prev curr

Step 3:  None ← 1 ← 2 ← 3   None
                        prev  curr

curr is None → return prev (3) ✓
```

---

## Solution — Recursive

```python
def reverse_list(head):
    if not head or not head.next:
        return head

    new_head = reverse_list(head.next)  # reverse the rest
    head.next.next = head               # make next node point back
    head.next = None                    # cut original forward pointer

    return new_head
```

**Time:** O(n)
**Space:** O(n) — call stack

---

## When to use which

| | Iterative | Recursive |
|---|---|---|
| Space | O(1) ✓ | O(n) call stack |
| Readability | Takes practice | Elegant once understood |
| Interview preference | Usually preferred | Good to know both |

---

## Key insight for iterative

Always save `curr.next` before overwriting `curr.next = prev`. Lose that reference and you've broken the list.

---

## Related problems

- [92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) — reverse between positions m and n
- [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) — reverse in chunks of k