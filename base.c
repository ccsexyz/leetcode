#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

void printList(struct ListNode *head) {
    int i = 0;
    while(head) {
        printf("val[%d] = %d\n", i++, head->val);
        head = head->next;
    }
}

int random_number() {
    return rand() % 1024;
}

struct ListNode *generate_random_list(int size) {
    assert(size > 0);
    struct ListNode *nodes = malloc(sizeof(struct ListNode) * size);
    for(int i = 0; i < size; i++) {
        nodes[i].val = random_number();
        nodes[i].next = &nodes[i + 1];
    }
    nodes[size - 1].next = NULL;
    return nodes;
}
