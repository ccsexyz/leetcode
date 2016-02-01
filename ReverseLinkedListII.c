#include "base.c"

// https://leetcode.com/problems/reverse-linked-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(m == n) return head;

    struct ListNode fuck_leetcode;
    fuck_leetcode.next = head;
    struct ListNode *p1, *p2, *prev, *cur = &fuck_leetcode, *next;
    for(int i = 0; i < m; p1 = cur, cur = cur->next, i++) ;
    n -= m;
    next = cur->next;
    for(int i = 0; i < n; i++) {
        struct ListNode *tmp = next->next;
        next->next = cur;
        cur = next;
        next = tmp;
    }
    p1->next->next = next;
    p1->next = cur;
    return fuck_leetcode.next;
}
