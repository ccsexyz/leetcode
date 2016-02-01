#include "base.c"

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) return NULL;
    else if(head->next == NULL) return head;

    int val;
    struct ListNode *p = head;
    struct ListNode *prev = NULL;
    for(; p && p->next; p = p->next) {
        if(p->val == p->next->val) {
            val = p->val;
            while(p->next && val == p->next->val)
                p = p->next;
            if(prev == NULL) {
                head = p->next;
            } else {
                prev->next = p->next;
                //prev = p->next;
            }
        } else {
            prev = p;
        }
    }

    return head;
}

int main(void)
{
    struct ListNode nodes[2];
    nodes[1].val = 2;
    nodes[0].val = 2;
    nodes[0].next = &(nodes[1]);
    nodes[1].next = NULL;
    struct ListNode *x = deleteDuplicates(nodes);
    printList(x);
}
