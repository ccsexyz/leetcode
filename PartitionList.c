// https://leetcode.com/submissions/detail/54996996/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *lhs = NULL, *lend = NULL, *rhs = NULL, *rend = NULL;
    while(head) {
        if(head->val >= x) {
            if(rhs == NULL) {
                rhs = rend = head;
            } else {
                rend->next = head;
                rend = head;
            }
        } else {
            if(lhs == NULL) {
                lhs = lend = head;
            } else {
                lend->next = head;
                lend = head;
            }
        }
        head = head->next;
    }
    if(lend == NULL) {
        if(rend != NULL)
            rend->next = NULL;
        return rhs;
    } else if(rend == NULL) {
        lend->next = NULL;
        return lhs;
    } else {
        lend->next = rhs;
        rend->next = NULL;
        return lhs;
    }
}
