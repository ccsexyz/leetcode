/*
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 */

#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode *p = head;
    struct ListNode *pnext = p->next;

    int val = p->val;
    p->val = pnext->val;
    pnext->val = val;

    if(pnext->next != NULL) {
        swapPairs(pnext->next);
    }
    return head;
}
