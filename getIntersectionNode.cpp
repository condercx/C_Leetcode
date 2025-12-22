#include "bits/stdc++.h"



struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int LenA=0, LenB=0;
    struct ListNode *curA = headA;
    struct ListNode *curB = headB;
    while (curA != NULL) {
        LenA++;
        curA = curA->next;
    }
    while (curB != NULL) {
        LenB++;
        curB = curB->next;
    }
    curA = headA;
    curB = headB;
    if (LenA < LenB) {
        struct ListNode *tmp;
        tmp = curA;
        curA = curB;
        curB = tmp;
    }
    int gap = abs(LenA - LenB);
    while (gap) {
        curA = curA->next;
        gap--;
    }
    while (curA != NULL && curB != NULL) {
        if (curA == curB) {
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}