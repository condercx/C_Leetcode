#include <bits/stdc++.h>

const int HASH_SIZE = 256;
typedef struct node {
    int val;
    int count;
    struct node* next;
}node, *Hashmap;

void hash_insert(Hashmap hashmap[], int val) {
    int idx = abs(val % HASH_SIZE);

    node* p = hashmap[idx];

    while (p->next != NULL) {
        p = p->next;
        if (p->val == val) {
            p->count++;
            return;
        }
    }

    node* new_node = (node*)malloc(sizeof(node));
    new_node->val = val;
    new_node->count = 1;
    new_node->next = NULL;
    p->next = new_node;
}

int hash_search(Hashmap hashmap[], int val) {
    int idx = abs(val % HASH_SIZE);

    node* p = hashmap[idx];

    while (p->next != NULL) {
        p = p->next;
        if (p->val == val) {
            return p->count;
        }
    }
    return 0;
}



int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size) {
    Hashmap hashmap[HASH_SIZE];
    int i, j;
    int count = 0, num;
    for (i = 0; i < HASH_SIZE; i++) {
        hashmap[i] = (node*)malloc(sizeof(node));
        hashmap[i]->next = NULL;
    }

    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            num = - (nums1[i] + nums2[j]);
            hash_insert(hashmap, num);
        }
    }

    for (i = 0; i < nums3Size; i++) {
        for (j = 0; j < nums4Size; j++) {
            num = nums3[i] + nums4[j];
            count += hash_search(hashmap, num);
        }
    }

    return count;
}