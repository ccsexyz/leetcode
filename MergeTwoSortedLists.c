/*
 * https://leetcode.com/problems/merge-two-sorted-lists/
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->val < l2->val) {
        struct ListNode *temp = l1->next;
        l1->next = mergeTwoLists(temp, l2);
        return l1;
    } else {
        struct ListNode *temp = l2->next;
        l2->next = mergeTwoLists(l1, temp);
        return l2;
    }
}

struct ListNode* mergeTwoLists_withloop(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    struct ListNode fuck_leetcode;
    struct ListNode *head = &fuck_leetcode;
    struct ListNode *p = head;

    while(l1 && l2) {
        if(l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    if(l1) {
        p->next = l1;
    } else {
        p->next = l2;
    }

    return head->next;
}
