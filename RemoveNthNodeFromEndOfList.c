#include "base.c"

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode fuck_leetcode;
    fuck_leetcode.next = head;
    struct ListNode *p1 = &fuck_leetcode, *p2 = &fuck_leetcode, *p = head;
    for(int i = 0; p; i++, p = p->next) {
        if(p1 != &fuck_leetcode) p1 = p1->next;
        if(p2 != &fuck_leetcode) p2 = p2->next;
        if(i == n - 1) {
            p2 = head;
        } else if(i == n) {
            p1 = head;
        }
    }
    p1->next = p2->next;
    return fuck_leetcode.next;
}

int main(void)
{
    struct ListNode *x = generate_random_list(5);
    printList(x);
    printf("\n");
    x = removeNthFromEnd(x, 5);
    printf("%p\n", x);
    printList(x);
}
