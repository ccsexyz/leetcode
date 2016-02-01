#include "base.c"

//https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL) {
        return NULL;
    }

    int size = 0;
    struct ListNode *p = head;
    for(; p; size++, p = p->next) ;

    int *vals = calloc(size, sizeof(int));
    p = head;
    for(int i = 0; i < size; i++, p = p->next)
        vals[i] = p->val;
    p = head;
    for(; p && size >= 0; p = p->next, size--)
        p->val = vals[size - 1];
    return head;
}

int main(void)
{
    struct ListNode *x = generate_random_list(5);
    printList(x);
    printList(reverseList(x));
    return 0;
}
