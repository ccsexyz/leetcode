// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(k == 0 || head == NULL || k == 1) return head;

    struct ListNode *ret = head;
    struct ListNode *start, *end;
    struct ListNode *prev = NULL, *curr = head, *temp, *left;

    while(1) {
        left = temp;
        temp = curr;
        for(int i = 0; i < k - 1 && curr != NULL; i++, curr = curr->next) ;
        if(curr == NULL) return ret;
        prev = curr->next;
        curr = temp;
        for(int i = 0; i < k; i++) {
            struct ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(ret == head) {
            ret = prev;
        } else {
            left->next = prev;
        }
    }
}
