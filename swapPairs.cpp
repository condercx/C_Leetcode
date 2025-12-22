#include <bits/stdc++.h>

struct ListNode{
    int val;
    struct ListNode* next;
};


struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode* pre = &dummyHead;
    while (pre->next != NULL && pre->next->next != NULL) {
        struct ListNode* node1 = pre->next;
        struct ListNode* node2 = pre->next->next;

        pre->next = node2;
        node1->next = node2->next;
        node2->next = node1;

        pre = node1;
    }
    return dummyHead.next;
}

// --- 辅助函数：创建节点 ---
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// --- 辅助函数：打印链表 ---
void printList(struct ListNode* head) {
    if (head == NULL) {
        printf("[]\n");
        return;
    }
    printf("[");
    while (head) {
        printf("%d%s", head->val, head->next ? "," : "");
        head = head->next;
    }
    printf("]\n");
}

int main() {
    // 案例 1: head = [1, 2, 3, 4]
    struct ListNode* h1 = createNode(1);
    h1->next = createNode(2);
    h1->next->next = createNode(3);
    h1->next->next->next = createNode(4);
    
    printf("输入 1: "); printList(h1);
    h1 = swapPairs(h1);
    printf("输出 1: "); printList(h1);

    // 案例 2: head = []
    struct ListNode* h2 = NULL;
    printf("\n输入 2: "); printList(h2);
    h2 = swapPairs(h2);
    printf("输出 2: "); printList(h2);

    // 案例 3: head = [1]
    struct ListNode* h3 = createNode(1);
    printf("\n输入 3: "); printList(h3);
    h3 = swapPairs(h3);
    printf("输出 3: "); printList(h3);

    return 0;
}
