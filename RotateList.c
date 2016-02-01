#include "base.c"

// https://leetcode.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k <= 0 || head == NULL)
        return head;

    struct ListNode *prev, *p, *ret, *tail;
    int size = 0;

    for(p = head; p; prev = p, p = p->next, size++) ;

    if(k > size)
        k = k % size;
    if(k == 0 || size == k)
        return head;

    tail = prev;
    k = size - k;
    for(p = head; p && k > 0; prev = p, p = p->next, k--) ;
    prev->next = NULL;
    ret = p;
    for(; p; prev = p, p = p->next) ;
    prev->next = head;
    return ret;
}

int main(void)
{
    struct ListNode *x = generate_random_list(2);
    printList(x);
    printList(rotateRight(x, 2));
}
