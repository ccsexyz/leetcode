#include "base.c"

// https://leetcode.com/problems/remove-linked-list-elements/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    struct ListNode fuck_leetcode;
    fuck_leetcode.next = head;
    struct ListNode *prev = &fuck_leetcode;
    struct ListNode *p = head;

    while(p) {
        if(p->val == val) {
            prev->next = p->next;
        } else {
            prev = p;
        }
        p = p->next;
    }

    return fuck_leetcode.next;
}
