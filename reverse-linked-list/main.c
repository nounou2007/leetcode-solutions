// this is not needed in leet code
// typedef struct ListNode
//{
//    int val;
//    struct ListNode *next;
// } ListNode;
struct ListNode *reverseList(struct ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
