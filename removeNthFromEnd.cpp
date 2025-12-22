#include "bits/stdc++.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode* slow = &dummy;
    struct ListNode* fast = &dummy;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* target = slow->next;
    slow->next = target->next;
    free(target);

    return dummy.next;
}


// --- 辅助工具函数 ---

// 创建链表
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

// 打印链表
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// --- 测试案例 ---
int main() {
    // 示例 1：head = [1,2,3,4,5], n = 2
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = createList(arr1, 5);
    printf("测试 1 原链表: ");
    printList(head1);
    head1 = removeNthFromEnd(head1, 2);
    printf("测试 1 结果 (n=2): ");
    printList(head1);
    printf("\n");

    // 示例 2：head = [1], n = 1
    int arr2[] = {1};
    struct ListNode* head2 = createList(arr2, 1);
    printf("测试 2 原链表: ");
    printList(head2);
    head2 = removeNthFromEnd(head2, 1);
    printf("测试 2 结果 (n=1): ");
    printList(head2);
    printf("\n");

    // 示例 3：head = [1,2], n = 1
    int arr3[] = {1, 2};
    struct ListNode* head3 = createList(arr3, 2);
    printf("测试 3 原链表: ");
    printList(head3);
    head3 = removeNthFromEnd(head3, 1);
    printf("测试 3 结果 (n=1): ");
    printList(head3);

    return 0;
}