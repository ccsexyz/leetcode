#include "base.c"

// https://leetcode.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL) return head;
    struct ListNode *ret = head, *p = head;
    head = head->next;
    ret->next = NULL;
    while(head) {
        p = ret;
        struct ListNode *prev = NULL;
        while(p && p->val < head->val) {
            prev = p;
            p = p->next;
        }
        if(prev == NULL) {
            prev = head;
            head = head->next;
            prev->next = ret;
            ret = prev;
        } else {
            prev->next = head;
            head = head->next;
            prev->next->next = p;
        }
    }
    return ret;
}
