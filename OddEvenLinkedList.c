#include "base.c"

// https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL) return NULL;
    struct ListNode *p = head;
    struct ListNode *odd = NULL, *even = NULL;
    struct ListNode *tmp = head->next;
    if(tmp == NULL) return head;
    for(int i = 0; p; p = p->next) {
        i++;
        if(i % 2 == 1) {
            //puts("odd");
            if(odd != NULL) {
                odd->next = p;
            }
            odd = p;
            //odd->next = NULL;
        } else {
            //puts("even");
            if(even != NULL) {
                even->next = p;
            }
            even = p;
            //even->next = NULL;
        }
    }
    odd->next = tmp;
    even->next = NULL;
    return head;
}

int main(void)
{
    struct ListNode *x = generate_random_list(3);
    struct ListNode *x1 = oddEvenList(x);
    printList(x1);
}
