#include "base.c"

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) return NULL;

    struct ListNode *p = head;
    struct ListNode fuck_leetcode;
    fuck_leetcode.val = head->val - 1;
    struct ListNode *prev = &fuck_leetcode;
    while(p) {
        if(prev->val == p->val) {
            prev->next = p->next;
        } else {
            prev = p;
        }
        p = p->next;
    }
    return head;
}

int main(void)
{
    ;
}
