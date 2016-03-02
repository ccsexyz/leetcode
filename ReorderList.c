//https://leetcode.com/submissions/detail/55000263/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    int n = 0;
    struct ListNode *temp = head;
    while(head) { head = head->next; n++; }
    head = temp;

    if(head == NULL) {
        return;
    }

    struct ListNode *SingleList = head, *DoubleList;
    for(int i = 0; i < n / 2; i++, SingleList = SingleList->next) ;
    DoubleList = SingleList->next;
    SingleList->next = NULL;
    SingleList = head;

    if(DoubleList == NULL) {
        return;
    }

    struct ListNode *prev = NULL, *curr = DoubleList;
    for(; curr; ) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    DoubleList = prev;
    struct ListNode *ret = SingleList, *tail = SingleList;
    SingleList = SingleList->next;

    for(int flag = 0; DoubleList; flag = !flag) {
        if(flag) {
            tail->next = SingleList;
            tail = SingleList;
            SingleList = SingleList->next;
        } else {
            tail->next = DoubleList;
            tail = DoubleList;
            DoubleList = DoubleList->next;
        }
    }
    if(SingleList) {
        tail->next = SingleList;
        tail = SingleList;
    }

    return ret;
}
