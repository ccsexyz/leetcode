#include "base.c"

// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p1 = head, *p2 = head;
    do {
        if(p1 && p1->next) {
            p1 = p1->next;
        } else {
            return false;
        }
        if(p2 && p2->next && p2->next->next) {
            p2 = p2->next->next;
        } else {
            return false;
        }
    } while(p1 && p2 && p1 != p2);
    if(p1 == p2) {
        return true;
    }
    return false;
}
