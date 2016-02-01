/*
 * https://leetcode.com/problems/merge-k-sorted-lists/
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
 /*
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0) {
        return NULL;
    } else if(listsSize == 1) {
        return lists[0];
    }

    struct ListNode **lists2 = malloc(sizeof(struct ListNode*) * (listsSize + 1));
    int listsSize2 = 0;

    for(int i = 0; i < listsSize; i++) {
        if(lists[i] != NULL) {
            lists2[listsSize2++ + 1] = lists[i];
        }
    }

    lists = lists2;
    listsSize = listsSize2;

    for(int i = 0; i < listsSize; i++) {
        struct ListNode *x = lists[i + 1];
        int hole = i + 1;
        for(; hole > 1 && x->val < lists[hole / 2]->val; hole /= 2) {
            lists[hole] = lists[hole / 2];
        }
        lists[hole] = x;
    }

    struct ListNode fuck_leetcode;
    struct ListNode *head = &fuck_leetcode;
    struct ListNode *p = head;

    while(1) {
        struct ListNode *x = lists[1];
        lists[1] = lists[listsSize--];
        int child;
        struct ListNode *tmp = lists[1];

        int hole = 1;
        for(; hole * 2 <= listsSize; hole = child) {
            child = hole * 2;
            if(child != listsSize && lists[child + 1] < lists[child])
                child++;
            if(lists[child]->val < tmp->val)
                lists[hole] = lists[child];
            else
                break;
        }
        lists[hole] = tmp;

        p->next = x;
        p = x;

        x = x->next;

        if(x == NULL) {
            struct ListNode *rest = mergeKLists(lists + 1, listsSize);
            p->next = rest;
            break;
        }

        hole = ++listsSize;
        for(; hole > 1 && x->val < lists[hole / 2]->val; hole /= 2)
            lists[hole] = lists[hole / 2];
        lists[hole] = x;
    }

    return head->next;
} */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0) {
        return NULL;
    } else if(listsSize == 1) {
        return lists[0];
    } else if(listsSize == 2) {
        struct ListNode *l1 = lists[0];
        struct ListNode *l2 = lists[1];

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
    } else {
        struct ListNode *L[2];
        L[0] = mergeKLists(lists, listsSize / 2);
        L[1] = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);
        return mergeKLists(L, 2);
    }
}

int main(void)
{
    struct ListNode **nodes = malloc(sizeof(void *) * 4);
    struct ListNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10, *n11, *n12;
    n1 = malloc(sizeof(struct ListNode));
    n2 = malloc(sizeof(struct ListNode));
    n3 = malloc(sizeof(struct ListNode));
    n4 = malloc(sizeof(struct ListNode));
    n5 = malloc(sizeof(struct ListNode));
    n6 = malloc(sizeof(struct ListNode));
    n7 = malloc(sizeof(struct ListNode));
    n8 = malloc(sizeof(struct ListNode));
    n9 = malloc(sizeof(struct ListNode));
    n10 = malloc(sizeof(struct ListNode));
    n11 = malloc(sizeof(struct ListNode));
    n12 = malloc(sizeof(struct ListNode));
    n1->val = 1; n1->next = n2;
    n2->val = 2; n2->next = n3;
    n3->val = 3; n3->next = NULL;
    n4->val = 4; n4->next = n5;
    n5->val = 5; n5->next = n6;
    n6->val = 6; n6->next = NULL;
    n7->val = 7; n7->next = n8;
    n8->val = 8; n8->next = n9;
    n9->val = 9; n9->next = NULL;
    n10->val = 10; n10->next = n11;
    n11->val = 11; n11->next = n12;
    n12->val = 12; n12->next = NULL;
    nodes[0] = n1;
    nodes[1] = n4;
    nodes[2] = n7;
    nodes[3] = n10;

    struct ListNode *x = mergeKLists(nodes, 4);

    printf("node in main\n");
    for(int i = 0; i < 4; i++) {
        printf("node[%d] = %p\n", i, nodes[i]);
    }

    while(x) {
        printf("x->val = %d\n", x->val);
        x = x->next;
    }

    return 0;
}
