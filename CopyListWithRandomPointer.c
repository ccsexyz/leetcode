// https://leetcode.com/problems/copy-list-with-random-pointer/

#include "base.c"

/**
  *Definition for singly-linked list with a random pointer.
  *struct RandomListNode {
  *    int label;
  *    struct RandomListNode *next;
  *    struct RandomListNode *random;
  *};
 */

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
        struct RandomListNode *ret = NULL;
        struct RandomListNode *p = head;
        struct RandomListNode *copy = NULL;
        struct RandomListNode *prev = NULL;

        if(head == NULL) {
            return NULL;
        }

        while(p != NULL) {
            copy = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
            if(copy != NULL) {
                copy->next = p->next;
                copy->label = p->label;
                p->next = copy;
                p = p->next->next;
            }
            else {
                break;
            }
        }

        p = head;
        while(p != NULL) {
            if(p->random != NULL) {
                p->next->random = p->random->next;
            }
            else {
                p->next->random = NULL;
            }

            p = p->next->next;
        }

        ret = head->next;
        p = head;
        while(p != NULL) {
            copy = p->next;

            p->next = copy->next;
            if(prev != NULL) {
                prev->next = copy;
            }
            prev = copy;
            p = copy->next;
        }

        return ret;
}
