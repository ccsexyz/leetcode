//https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *n1, *n2;
    if(head == NULL) return NULL;
    n1 = head;
    n2 = head->next;
    while(n1 != n2 && n1 && n2) {
        n1 = n1->next;
        n2 = n2->next;
        if(!n2) return NULL;
        n2 = n2->next;
    }
    if(n1 == NULL || n2 == NULL) return NULL;
    struct ListNode *CycleNode = n1;
    while(head) {
        struct ListNode *test = head;
        do {
            if(head == n1) {
                return n1;
            }
            n1 = n1->next;
        } while(n1 != CycleNode);
        n1 = CycleNode;
        head = head->next;
    }
}
