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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    int k = 2;
    if(k == 0 || head == NULL || k == 1) return head;

    struct ListNode *ret = head;
    struct ListNode *start, *end;
    struct ListNode *prev = NULL, *curr = head, *temp, *left;

    while(1) {
        left = temp;
        temp = curr;
        for(int i = 0; i < k - 1 && curr != NULL; i++, curr = curr->next) ;
        if(curr == NULL) return ret;
        prev = curr->next;
        curr = temp;
        for(int i = 0; i < k; i++) {
            struct ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(ret == head) {
            ret = prev;
        } else {
            left->next = prev;
        }
    }
}
