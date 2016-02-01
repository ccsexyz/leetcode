#include "base.c"

//https://leetcode.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL) {
        return NULL;
    }

    int size = 0, size1, size2;
    struct ListNode *p = head;
    for(; p; size++, p = p->next) ;

    if(size == 0) {
        return NULL;
    } else if(size == 1) {
        return head;
    } else if(size == 2) {
        if(head->val > head->next->val) {
            int val = head->val;
            head->val = head->next->val;
            head->next->val = val;
        }
        return head;
    }

    size1 = size / 2;
    size2 = size - size1;
    p = head;
    for(int i = 0; p && i < size1 - 1; i++, p = p->next);
    struct ListNode *p2 = p->next;
    p->next = NULL;

    head = sortList(head);
    p2 = sortList(p2);

    struct ListNode *l1 = head;
    struct ListNode *l2 = p2;

    struct ListNode fuck_leetcode;
    head = &fuck_leetcode;
    p = head;

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

    //printList(head->next);

    return head->next;
}

int main(void)
{
    struct ListNode *x = generate_random_list(10);
    //printList(x);
    x = sortList(x);
    printList(x);
}
